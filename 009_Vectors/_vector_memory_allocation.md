
# **Static vs Dynamic Memory Allocation in `std::vector`**

---

## **1. Does `vector` use static or dynamic memory allocation?**

* A **vector object itself (metadata like size, capacity, pointer)** is usually stored **on the stack** when declared normally → **static allocation**.
* The **actual elements of the vector** are stored on the **heap** → **dynamic allocation**, because:

  * The size of a vector is not fixed.
  * It can grow or shrink at runtime.

So, **vectors combine both**:
✔ Metadata → Static
✔ Elements → Dynamic

---

### **Internal Representation of `vector`**

A `std::vector` internally has:

* **Pointer** to the dynamically allocated array (on heap).
* **Size** (number of elements currently stored).
* **Capacity** (how many elements can be stored before resizing).

So memory looks like this:

```
Stack (Static): [ vector object { pointer → heap, size, capacity } ]
Heap  (Dynamic): [ elements stored dynamically ]
```

---

## **2. How does static vs dynamic allocation occur in vectors?**

| Part of Vector   | Where Stored | Allocation Type |
| ---------------- | ------------ | --------------- |
| Vector object    | Stack        | Static          |
| Elements (array) | Heap         | Dynamic         |

---

### **Example**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v; // Vector object on stack (static)

    for (int i = 1; i <= 5; i++) {
        v.push_back(i); // Elements stored on heap (dynamic)
        cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;
    }
}
```

✔ The `vector` object (`v`) is stored on **stack**, but every time `push_back()` adds elements, memory for elements is **dynamically allocated** on the heap.
✔ When **capacity is exceeded**, vector **allocates a new bigger block on heap** and copies old elements (this is dynamic allocation).

---

---

## **3. Static vs Dynamic in Context of Vector**

| **Feature**         | **Static Allocation in Vector**                      | **Dynamic Allocation in Vector**                          |
| ------------------- | ---------------------------------------------------- | --------------------------------------------------------- |
| **What is stored?** | Vector metadata (pointer, size, capacity)            | Actual elements of the vector                             |
| **When?**           | When you declare `vector<int> v;`                    | When you `push_back()` or change size dynamically         |
| **Flexibility**     | Cannot change after object creation (metadata fixed) | Can grow or shrink by allocating/reallocating on the heap |
| **Memory location** | Stack                                                | Heap                                                      |

---

---

## **4. Can a vector be fully static?**

* If you **use `std::array` or raw arrays**, memory is **completely static** (fixed size).
* `std::vector` **always uses dynamic allocation for elements**, even if you know the size in advance (though `reserve()` can reduce reallocations).

---

---

## **Internal Behavior on Growth**

When capacity is full:

* A new larger block is allocated dynamically (usually **double the current capacity**).
* Old elements are copied to the new block.
* Old memory is freed.

Example:

```cpp
vector<int> v;
v.push_back(1); // capacity might be 1
v.push_back(2); // capacity becomes 2
v.push_back(3); // capacity becomes 4
v.push_back(4); // capacity remains 4
v.push_back(5); // capacity becomes 8
```

---

---

## **Key Takeaways**

* **Vector object itself = static allocation (on stack)**.
* **Vector elements = dynamic allocation (on heap)**.
* When vector grows, **dynamic reallocation happens**.
* Use `reserve()` to **reduce dynamic allocations** if you know the size in advance.

---

---

### **Example with Capacity Doubling**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        cout << "Inserted: " << i 
             << " | Size: " << v.size() 
             << " | Capacity: " << v.capacity();
        
        if (v.size() == v.capacity()) {
            cout << "  <-- Capacity full, next push_back will cause reallocation (likely doubles)";
        }
        cout << endl;
    }
}
```

---

### **Sample Output**

```
Inserted: 1 | Size: 1 | Capacity: 1  <-- Capacity full, next push_back will cause reallocation (likely doubles)
Inserted: 2 | Size: 2 | Capacity: 2  <-- Capacity full, next push_back will cause reallocation (likely doubles)
Inserted: 3 | Size: 3 | Capacity: 4
Inserted: 4 | Size: 4 | Capacity: 4  <-- Capacity full, next push_back will cause reallocation (likely doubles)
Inserted: 5 | Size: 5 | Capacity: 8
Inserted: 6 | Size: 6 | Capacity: 8
Inserted: 7 | Size: 7 | Capacity: 8
Inserted: 8 | Size: 8 | Capacity: 8  <-- Capacity full, next push_back will cause reallocation (likely doubles)
Inserted: 9 | Size: 9 | Capacity: 16
Inserted:10 | Size:10 | Capacity:16
```

---

✔ This demonstrates:

* **Capacity doubles** when old capacity is exceeded (1 → 2 → 4 → 8 → 16).
* Actual growth factor depends on implementation, but generally **2X rule applies in GCC and MSVC**.

---

---


✔ **Why capacity doubles**
✔ **Impact on time complexity (amortized O(1))**
✔ **Diagram of reallocation steps**
✔ **Explanation in simple terms**

---

# **Why Does `std::vector` Double Capacity and What is Amortized O(1)?**

---

## **1. Why Does Capacity Double?**

* When you `push_back()` and **capacity is full**, the vector **cannot add the new element in the current memory block**.
* It must:

  1. **Allocate a new larger block** (usually **2× current capacity**).
  2. **Copy all old elements** into the new block.
  3. **Free the old memory**.
* Doubling ensures **fewer reallocations**, reducing overhead.

### **Example of Capacity Growth**

```
Initial capacity = 1
Insert 1 → capacity = 1
Insert 2 → capacity = 2 (doubled)
Insert 3 → capacity = 4 (doubled)
Insert 5 → capacity = 8 (doubled)
Insert 9 → capacity = 16 (doubled)
```

---

---

## **2. Diagram of Reallocation Steps**

```
Before push_back(3):              After push_back(3):
Capacity = 2                      Capacity = 4
Heap: [10][20]                    New Heap: [10][20][30][  ]
                                   ↑
                              Elements copied here
```

✔ This process happens **only when capacity is exceeded**.

---

---

## **3. How Does This Affect Time Complexity?**

* **push\_back() normally takes O(1)** because inserting at the end is constant time.
* But **when capacity doubles**, copying all elements takes **O(n)**.
* However, because doubling happens **rarely**, the **average (amortized) cost is O(1)**.

### **Why amortized O(1)?**

* For `n` insertions, the total cost of reallocations:

  ```
  n + n/2 + n/4 + ... + 1 ≈ 2n
  ```
* So average = `2n / n = O(1)`.

---

---

### **Program Demonstrating Doubling and Address Change**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    cout << "Stack Address of vector object: " << &v << endl;

    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        cout << "Inserted: " << i 
             << " | Size: " << v.size() 
             << " | Capacity: " << v.capacity()
             << " | Heap Address: " << v.data();
        
        if (v.size() == v.capacity()) {
            cout << "  <-- Capacity FULL (next push_back will reallocate)";
        }
        cout << endl;
    }
}
```

✔ This will show how **capacity doubles** and **heap address changes** when reallocation occurs.

---

---

### **Comparison Table Recap**

| **Feature**            | **Static Array** | **Vector**               | **Dynamic Array (new)**            |
| ---------------------- | ---------------- | ------------------------ | ---------------------------------- |
| **Size at runtime**    | ❌ Fixed          | ✅ Flexible               | ✅ Fixed (must reallocate manually) |
| **Memory Location**    | Stack            | Stack + Heap             | Heap                               |
| **Automatic resizing** | ❌ No             | ✅ Yes (capacity doubles) | ❌ No                               |
| **Manual free needed** | ❌ No             | ❌ No                     | ✅ Yes (`delete[]`)                 |

---

---

---

# **1. Diagram of Memory Layout (Stack vs Heap)**

```
+-------------------+           +---------------------------+
|       Stack       |           |           Heap           |
+-------------------+           +---------------------------+
| vector<int> v     |           | [10][20][30][40][...]    |
| - pointer ------> | --------> | Dynamically allocated    |
| - size            |           | memory for elements      |
| - capacity        |           |                           |
+-------------------+           +---------------------------+
```

**Explanation:**

* The **vector object (metadata)** lives on the **stack**.
* The **actual elements** live on the **heap** (allocated dynamically).
* When capacity is exceeded, **a new larger block** is allocated on heap, old elements are copied, and old block is freed.

---

---

# **2. Program to Print Addresses (Proof)**

This program will:
✔ Print the address of the **vector object (stack)**.
✔ Print the address of the **internal array (heap)**.
✔ Show how heap memory changes after reallocation.

---

### **Code**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    cout << "Address of vector object (stack): " << &v << endl;

    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        cout << "Inserted " << i
             << " | Size: " << v.size()
             << " | Capacity: " << v.capacity()
             << " | Heap Address (data): " << v.data() << endl;
    }
}
```

---

### **Sample Output**

```
Address of vector object (stack): 0x7ffcd0b8
Inserted 1 | Size: 1 | Capacity: 1 | Heap Address: 0x55b2a4d0
Inserted 2 | Size: 2 | Capacity: 2 | Heap Address: 0x55b2a4f0
Inserted 3 | Size: 3 | Capacity: 4 | Heap Address: 0x55b2a510
Inserted 4 | Size: 4 | Capacity: 4 | Heap Address: 0x55b2a510
Inserted 5 | Size: 5 | Capacity: 8 | Heap Address: 0x55b2a530
```

✔ Notice:

* The **stack address** (vector object) never changes.
* The **heap address** (data pointer) changes when reallocation occurs (capacity doubles).

---

---

# **3. Comparison Table: `array` vs `vector` vs `dynamic array (new)`**

| Feature                | **Static Array** (`int arr[5]`) | **std::vector<int>**             | **Dynamic Array** (`int* arr = new int[n];`)   |
| ---------------------- | ------------------------------- | -------------------------------- | ---------------------------------------------- |
| **Size at runtime?**   | ❌ Fixed at compile time         | ✅ Can grow/shrink                | ✅ Fixed at runtime but can reallocate manually |
| **Memory location**    | Stack                           | Stack (object) + Heap (elements) | Heap only                                      |
| **Automatic resizing** | ❌ No                            | ✅ Yes                            | ❌ No                                           |
| **Bound checking**     | ❌ No                            | ✅ `at()` provides safe access    | ❌ No                                           |
| **Initialization**     | `int arr[5] = {1,2,3};`         | `vector<int> v{1,2};`            | Manual (`arr[i] = ...`)                        |
| **Deallocation**       | Automatic                       | Automatic                        | Manual (`delete[] arr;`)                       |
| **Ease of use**        | Simple but rigid                | Easiest, safe, feature-rich      | Manual, error-prone                            |

---

---

## Key Insights:

* **Static Array** = **fast, simple, but fixed size**.
* **Vector** = **flexible, dynamic, automatic resizing, safest for most use cases**.
* **Dynamic Array (new)** = **flexible but manual memory management** (risk of memory leaks).

---