
# **C++ Vector Functions – Part 1**

---

## **1. Element Access Functions**

These allow **reading and modifying elements** inside the vector.

| **Function** | **Explanation**                                                               |
| ------------ | ----------------------------------------------------------------------------- |
| `v[i]`       | Directly access element at index `i`. No bounds check. Fast but unsafe.       |
| `at(i)`      | Access element with **bounds check**. Throws `out_of_range` if invalid index. |
| `front()`    | Returns the **first element** in the vector.                                  |
| `back()`     | Returns the **last element** in the vector.                                   |
| `data()`     | Returns a **pointer** to the internal array used by the vector.               |

---

### **Example**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    cout << v[1] << endl;        // 20 (no check)
    cout << v.at(1) << endl;     // 20 (safe)
    cout << v.front() << endl;   // 10
    cout << v.back() << endl;    // 30
    int* p = v.data();
    cout << *p << endl;          // 10 (first element via pointer)
}
```

---

## **2. Capacity Functions**

These manage the **size and memory** of the vector.

| **Function**      | **Explanation**                                                            |
| ----------------- | -------------------------------------------------------------------------- |
| `size()`          | Current number of elements in the vector.                                  |
| `capacity()`      | Memory allocated (can be more than `size()` to reduce reallocations).      |
| `max_size()`      | Maximum possible number of elements (system limit).                        |
| `empty()`         | Returns `true` if vector has **no elements**.                              |
| `resize(n)`       | Changes size to `n`. Fills new elements with default value if expanded.    |
| `reserve(n)`      | Pre-allocates space for **at least n elements** (to optimize performance). |
| `shrink_to_fit()` | Reduces capacity to exactly match current size (frees unused memory).      |

---

### **Example**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    cout << "Size: " << v.size() << endl;           // 2
    cout << "Capacity: " << v.capacity() << endl;   // Might be 2 or 4
    cout << (v.empty() ? "Empty" : "Not Empty") << endl;

    v.resize(5);  // Now {1, 2, 0, 0, 0}
    v.reserve(10);
    cout << "After reserve, capacity: " << v.capacity() << endl;

    v.shrink_to_fit();
    cout << "After shrink, capacity: " << v.capacity() << endl;
}
```

---

## **3. Iterators**

Iterators behave like **pointers** and allow traversal.

| **Iterator** | **Purpose**                                               |
| ------------ | --------------------------------------------------------- |
| `begin()`    | Iterator to first element.                                |
| `end()`      | Iterator past the last element (not the last element).    |
| `rbegin()`   | Reverse iterator to last element (used in reverse loops). |
| `rend()`     | Reverse iterator before first element.                    |
| `cbegin()`   | Constant iterator to first element.                       |
| `cend()`     | Constant iterator past last element.                      |

---

### **Example**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    cout << "Forward: ";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "Reverse: ";
    for (auto rit = v.rbegin(); rit != v.rend(); rit++)
        cout << *rit << " ";
}
```

---

## **Summary Table (Part 1)**

| **Category**       | **Functions**                                                                               |
| ------------------ | ------------------------------------------------------------------------------------------- |
| **Element Access** | `operator[]`, `at()`, `front()`, `back()`, `data()`                                         |
| **Capacity**       | `size()`, `capacity()`, `max_size()`, `empty()`, `resize()`, `reserve()`, `shrink_to_fit()` |
| **Iterators**      | `begin()`, `end()`, `rbegin()`, `rend()`, `cbegin()`, `cend()`                              |

---

---

# **C++ Vector Functions – Part 2 (Modifiers, Comparison, Internal Working, Time Complexity)**

---

## **4. Modifiers (Add, Remove, Modify Elements)**

These functions **change the contents of the vector**.

| **Function**        | **Explanation**                                                                     |
| ------------------- | ----------------------------------------------------------------------------------- |
| `push_back(val)`    | Adds an element at the **end** of the vector.                                       |
| `pop_back()`        | Removes the **last element**.                                                       |
| `insert(pos, val)`  | Inserts an element at a specific position.                                          |
| `erase(pos)`        | Removes an element at a specific position.                                          |
| `erase(start, end)` | Removes a **range of elements**.                                                    |
| `clear()`           | Removes **all elements** from the vector (makes it empty).                          |
| `assign(n, val)`    | Replaces the vector with **n copies** of `val`.                                     |
| `swap(v2)`          | Swaps contents with another vector in **O(1)** time.                                |
| `emplace(pos, val)` | Inserts an element at `pos` **directly constructed in place** (faster than insert). |
| `emplace_back(val)` | Adds element at the end, **constructed in place** (faster than push\_back).         |

---

### **Detailed Explanation**

* **push\_back(val)** → Most commonly used. Time complexity: **O(1)** amortized.
* **pop\_back()** → Just removes last element. **O(1)**.
* **insert()** → Expensive if inserting at the beginning or middle. **O(n)**.
* **erase()** → Similar to insert, **O(n)**.
* **clear()** → Deletes all elements, **O(n)**.
* **assign()** → Used to **reset vector with given size and value**.
* **swap()** → Efficient, just swaps pointers internally.
* **emplace()** and **emplace\_back()** → Construct objects directly in place (avoids copying).

---

### **Example**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    v.push_back(40);                // {10, 20, 30, 40}
    v.pop_back();                   // {10, 20, 30}
    v.insert(v.begin() + 1, 15);    // {10, 15, 20, 30}
    v.erase(v.begin() + 2);         // {10, 15, 30}
    v.assign(5, 100);               // {100, 100, 100, 100, 100}
    v.emplace_back(200);            // Adds 200 at the end

    cout << "Vector: ";
    for (int x : v) cout << x << " ";
}
```

---

## **5. Comparison Operators**

Vectors can be compared using:

* **`==`** → True if both vectors have **same size and elements**.
* **`!=`** → True if they are not equal.
* **`<`, `>`, `<=`, `>=`** → Lexicographical comparison (like dictionary order).

---

### **Example**

```cpp
vector<int> a = {1, 2, 3};
vector<int> b = {1, 2, 3};
vector<int> c = {1, 3};

cout << (a == b) << endl;  // 1 (true)
cout << (a < c) << endl;   // 1 (true, because 2 < 3)
```

---

## **6. Internal Working – Size vs Capacity**

* **Size** → Actual number of elements.
* **Capacity** → Allocated memory (in terms of number of elements).
* When capacity is **full**, vector **doubles its capacity** (amortized O(1) push\_back).
* This is why `push_back()` is mostly O(1), but occasionally O(n) when reallocation happens.

### **Example showing capacity growth**

```cpp
vector<int> v;
for (int i = 0; i < 10; i++) {
    v.push_back(i);
    cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;
}
```

---

## **7. Time Complexity Table**

| **Operation**          | **Time Complexity** |
| ---------------------- | ------------------- |
| Access by index        | O(1)                |
| `push_back()`          | O(1) amortized      |
| `pop_back()`           | O(1)                |
| `insert()` / `erase()` | O(n)                |
| `clear()`              | O(n)                |
| `resize()`             | O(n)                |
| `reserve()`            | O(n) amortized      |
| `swap()`               | O(1)                |

---

## **Summary Table (Part 2)**

| **Category**   | **Functions**                                                                                                      |
| -------------- | ------------------------------------------------------------------------------------------------------------------ |
| **Modifiers**  | `push_back()`, `pop_back()`, `insert()`, `erase()`, `clear()`, `assign()`, `swap()`, `emplace()`, `emplace_back()` |
| **Comparison** | `==`, `!=`, `<`, `>`, `<=`, `>=`                                                                                   |

---