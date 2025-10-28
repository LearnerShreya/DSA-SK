# STL Tutorial One Shot

---

# **C++ STL (Standard Template Library)**

---

## **1. Introduction to STL**

### **What is STL?**

The **Standard Template Library (STL)** in C++ is a powerful library that provides **ready-to-use classes and functions** for common data structures and algorithms.
It saves time, reduces errors, and improves code efficiency.

### **Main Components of STL**

1. **Containers** – Store and manage collections of data.
2. **Iterators** – Point to elements in containers and allow traversal.
3. **Algorithms** – Provide operations like sorting, searching, reversing, etc.
4. **Functions** – Include function objects (functors) and utility functions.

---

## **2. Containers**

A **container** is a data structure template that stores a collection of objects.
All containers are part of the **`<vector>`, `<list>`, `<deque>`, `<set>`, `<map>`, `<queue>`, `<stack>`** headers.

### **Classification of Containers**

1. **Sequence Containers** – Store data in a linear order.

   * `vector`
   * `list`
   * `deque`

2. **Associative Containers** – Store data in key-value or sorted sets.

   * `set`, `multiset`
   * `map`, `multimap`

3. **Unordered Containers** – Use hash tables (faster access).

   * `unordered_set`, `unordered_multiset`
   * `unordered_map`, `unordered_multimap`

4. **Container Adapters** – Simplified interfaces for specific uses.

   * `stack`
   * `queue`
   * `priority_queue`

---

## **2.1 Sequence Containers**

These maintain the **order of insertion** and allow **sequential access**.

---

### **A. Vector**

#### **Definition**

A **vector** is a **dynamic array** that can resize itself when elements are inserted or deleted.

#### **Header File**

```cpp
#include <vector>
using namespace std;
```

#### **Syntax**

```cpp
vector<data_type> name;
vector<int> v;                // Empty vector
vector<int> v = {1, 2, 3};    // Initialization list
vector<int> v(5, 10);         // 5 elements with value 10
vector<int> v2(v1);           // Copy constructor
```

---

#### **Key Features**

* Random access (like an array)
* Dynamic resizing (size grows automatically)
* Continuous memory storage
* Efficient insertion/deletion at the **end**
* Insertion/deletion in the **middle or front** is costly (O(n))

---

#### **Important Functions**

| Function             | Description                            | Example                     |
| -------------------- | -------------------------------------- | --------------------------- |
| `v.size()`           | Returns number of elements             | `cout << v.size();`         |
| `v.capacity()`       | Returns memory capacity                | `cout << v.capacity();`     |
| `v.push_back(x)`     | Adds element at end                    | `v.push_back(5);`           |
| `v.pop_back()`       | Removes last element                   | `v.pop_back();`             |
| `v.emplace_back(x)`  | Inserts at end (faster than push_back) | `v.emplace_back(10);`       |
| `v.at(i)`            | Access element with bounds checking    | `cout << v.at(2);`          |
| `v[i]`               | Access element without bounds check    | `cout << v[2];`             |
| `v.front()`          | Returns first element                  | `cout << v.front();`        |
| `v.back()`           | Returns last element                   | `cout << v.back();`         |
| `v.clear()`          | Removes all elements                   | `v.clear();`                |
| `v.empty()`          | Checks if empty                        | `if(v.empty())`             |
| `v.insert(pos, val)` | Inserts at specific position           | `v.insert(v.begin()+2, 7);` |
| `v.erase(pos)`       | Deletes element at position            | `v.erase(v.begin()+1);`     |
| `v.begin()`          | Iterator to first element              | `auto it = v.begin();`      |
| `v.end()`            | Iterator after last element            | `auto it = v.end();`        |

---

#### **Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};

    v.push_back(4);
    v.emplace_back(5);

    cout << "Vector elements: ";
    for(int x : v) cout << x << " ";

    cout << "\nFront: " << v.front();
    cout << "\nBack: " << v.back();
    cout << "\nSize: " << v.size();
    cout << "\nCapacity: " << v.capacity();

    v.pop_back();
    v.erase(v.begin());  // remove first element

    cout << "\nAfter operations: ";
    for(int x : v) cout << x << " ";
}
```

**Output:**

```
Vector elements: 1 2 3 4 5
Front: 1
Back: 5
Size: 5
Capacity: 6
After operations: 2 3 4
```

---

### **B. List**

#### **Definition**

A **list** is a **doubly linked list**, allowing insertion and deletion from both ends efficiently.

#### **Header File**

```cpp
#include <list>
using namespace std;
```

#### **Syntax**

```cpp
list<int> l;              // empty list
list<int> l = {1, 2, 3};  // initialization list
list<int> l2(l1);         // copy list
```

---

#### **Key Features**

* No random access (like array)
* Efficient insertion and deletion **anywhere** (O(1))
* Uses **doubly linked structure**
* Stores non-contiguous memory

---

#### **Important Functions**

| Function                 | Description                  |
| ------------------------ | ---------------------------- |
| `l.push_back(x)`         | Adds element at end          |
| `l.push_front(x)`        | Adds element at front        |
| `l.emplace_back(x)`      | Constructs and adds at end   |
| `l.emplace_front(x)`     | Constructs and adds at front |
| `l.pop_back()`           | Removes from end             |
| `l.pop_front()`          | Removes from front           |
| `l.front()`              | Returns first element        |
| `l.back()`               | Returns last element         |
| `l.size()`               | Returns number of elements   |
| `l.clear()`              | Removes all elements         |
| `l.empty()`              | Checks if list is empty      |
| `l.erase(pos)`           | Erases element at position   |
| `l.insert(pos, val)`     | Inserts at given iterator    |
| `l.begin()`, `l.end()`   | Iterators                    |
| `l.rbegin()`, `l.rend()` | Reverse iterators            |

---

#### **Example**

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {1, 2, 3};

    l.push_front(0);
    l.push_back(4);
    l.emplace_front(-1);
    l.emplace_back(5);

    cout << "List elements: ";
    for (int x : l) cout << x << " ";

    l.pop_front();
    l.pop_back();

    cout << "\nAfter pop: ";
    for (int x : l) cout << x << " ";
}
```

**Output:**

```
List elements: -1 0 1 2 3 4 5
After pop: 0 1 2 3 4
```

---

### **C. Deque (Double Ended Queue)**

#### **Definition**

A **deque** (Double Ended Queue) allows **insertion and deletion from both ends** and supports **random access**.

#### **Header File**

```cpp
#include <deque>
using namespace std;
```

#### **Syntax**

```cpp
deque<int> d;
deque<int> d = {1, 2, 3};
```

---

#### **Key Features**

* Dynamic array structure
* Random access supported
* Efficient insertion/deletion at **both ends**
* Internally segmented array (not contiguous like vector)

---

#### **Important Functions**

| Function                 | Description                               |
| ------------------------ | ----------------------------------------- |
| `d.push_back(x)`         | Add element at end                        |
| `d.push_front(x)`        | Add element at front                      |
| `d.emplace_back(x)`      | Add element at end (construct in place)   |
| `d.emplace_front(x)`     | Add element at front (construct in place) |
| `d.pop_back()`           | Remove element from end                   |
| `d.pop_front()`          | Remove element from front                 |
| `d.front()`              | First element                             |
| `d.back()`               | Last element                              |
| `d.size()`               | Number of elements                        |
| `d.clear()`              | Removes all                               |
| `d.erase(pos)`           | Delete element at position                |
| `d.insert(pos, val)`     | Insert element at position                |
| `d.begin()`, `d.end()`   | Iterators                                 |
| `d.rbegin()`, `d.rend()` | Reverse iterators                         |

---

#### **Example**

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d = {1, 2, 3};
    d.push_front(0);
    d.push_back(4);
    d.emplace_front(-1);
    d.emplace_back(5);

    cout << "Deque elements: ";
    for (int x : d) cout << x << " ";

    d.pop_front();
    d.pop_back();

    cout << "\nAfter pop: ";
    for (int x : d) cout << x << " ";
}
```

**Output:**

```
Deque elements: -1 0 1 2 3 4 5
After pop: 0 1 2 3 4
```

---

### **Summary – Sequence Containers**

| Feature                 | Vector     | List        | Deque     |
| ----------------------- | ---------- | ----------- | --------- |
| Memory Type             | Contiguous | Linked List | Segmented |
| Random Access           | Yes        | No          | Yes       |
| Insert/Delete at End    | Fast       | Fast        | Fast      |
| Insert/Delete at Front  | Slow       | Fast        | Fast      |
| Insert/Delete in Middle | Slow       | Fast        | Moderate  |

---

Next part will cover:

### **➡ 2.2 Non-Sequence Containers**

(Stack, Queue, Priority Queue)
and

### **➡ 2.3 Associative Containers (Map, Set, etc.)**