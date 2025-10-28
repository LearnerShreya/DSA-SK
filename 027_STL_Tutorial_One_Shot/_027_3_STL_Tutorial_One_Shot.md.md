# STL Tutorial One Shot

---

# **C++ STL Detailed Notes – Part 2**

## **2.2 Non-Sequence Containers (Container Adapters)**

These containers **don’t provide direct data storage mechanisms** like vectors or lists.
Instead, they act as **interfaces (wrappers)** built on top of other containers (usually `deque` or `list`) to provide specific behaviors such as **LIFO** or **FIFO**.

---

### **A. Stack (LIFO – Last In, First Out)**

#### **Definition**

A **stack** stores elements such that the **last element inserted is the first to be removed**.

#### **Header File**

```cpp
#include <stack>
using namespace std;
```

#### **Syntax**

```cpp
stack<int> s;
stack<string> s2;
```

#### **Underlying Container**

By default, it uses **deque** internally, but can also use **vector** or **list**.

---

#### **Key Functions**

| Function       | Description                        | Example             |
| -------------- | ---------------------------------- | ------------------- |
| `s.push(x)`    | Insert element at top              | `s.push(10);`       |
| `s.emplace(x)` | Construct and push at top (faster) | `s.emplace(20);`    |
| `s.pop()`      | Remove top element                 | `s.pop();`          |
| `s.top()`      | Returns reference to top element   | `cout << s.top();`  |
| `s.size()`     | Returns number of elements         | `cout << s.size();` |
| `s.empty()`    | Returns true if stack is empty     | `if (s.empty())`    |
| `s.swap(s2)`   | Swaps contents with another stack  | `s.swap(s2);`       |

---

#### **Example**

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.emplace(30);

    cout << "Top element: " << s.top() << endl; // 30
    s.pop();
    cout << "After pop, top: " << s.top() << endl;

    cout << "Stack size: " << s.size() << endl;
    cout << "Is stack empty? " << s.empty() << endl;
}
```

**Output:**

```
Top element: 30
After pop, top: 20
Stack size: 2
Is stack empty? 0
```

---

### **B. Queue (FIFO – First In, First Out)**

#### **Definition**

A **queue** stores elements in such a way that the **first element inserted is the first one to be removed**.

#### **Header File**

```cpp
#include <queue>
using namespace std;
```

#### **Syntax**

```cpp
queue<int> q;
queue<string> q2;
```

#### **Underlying Container**

By default uses **deque** internally.

---

#### **Key Functions**

| Function       | Description                    | Example              |
| -------------- | ------------------------------ | -------------------- |
| `q.push(x)`    | Insert element at end (rear)   | `q.push(10);`        |
| `q.emplace(x)` | Construct and insert at end    | `q.emplace(20);`     |
| `q.pop()`      | Remove element from front      | `q.pop();`           |
| `q.front()`    | Access the front element       | `cout << q.front();` |
| `q.back()`     | Access the last (rear) element | `cout << q.back();`  |
| `q.size()`     | Number of elements             | `cout << q.size();`  |
| `q.empty()`    | Check if empty                 | `if (q.empty())`     |
| `q.swap(q2)`   | Swap two queues                | `q.swap(q2);`        |

---

#### **Example**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.emplace(30);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    q.pop();
    cout << "After pop, front: " << q.front() << endl;

    cout << "Queue size: " << q.size() << endl;
}
```

**Output:**

```
Front: 10
Back: 30
After pop, front: 20
Queue size: 2
```

---

### **C. Priority Queue (Heap)**

#### **Definition**

A **priority_queue** is a type of queue where **elements are stored in a sorted order** (based on priority).
The element with the **highest priority (largest value by default)** appears at the **top**.

#### **Header File**

```cpp
#include <queue>
using namespace std;
```

---

#### **Types**

1. **Max-Heap (default)** – Top element is maximum.

   ```cpp
   priority_queue<int> pq;
   ```
2. **Min-Heap** – Top element is minimum.

   ```cpp
   priority_queue<int, vector<int>, greater<int>> pq;
   ```

---

#### **Key Functions**

| Function        | Description                           | Example              |
| --------------- | ------------------------------------- | -------------------- |
| `pq.push(x)`    | Insert element                        | `pq.push(10);`       |
| `pq.emplace(x)` | Construct and push element            | `pq.emplace(15);`    |
| `pq.pop()`      | Remove top element                    | `pq.pop();`          |
| `pq.top()`      | Return top (highest priority) element | `cout << pq.top();`  |
| `pq.size()`     | Number of elements                    | `cout << pq.size();` |
| `pq.empty()`    | Check if empty                        | `if (pq.empty())`    |

---

#### **Example**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Max-Heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Max-Heap elements: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    // Min-Heap
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(10);
    minpq.push(30);
    minpq.push(20);

    cout << "\nMin-Heap elements: ";
    while (!minpq.empty()) {
        cout << minpq.top() << " ";
        minpq.pop();
    }
}
```

**Output:**

```
Max-Heap elements: 30 20 10
Min-Heap elements: 10 20 30
```

---

## **2.3 Associative Containers**

Associative containers store data in **sorted or hashed order**, allowing **fast searching and access**.

---

### **A. Map**

#### **Definition**

A **map** is an associative container that stores **key-value pairs**, where **keys are unique** and sorted automatically.

#### **Header File**

```cpp
#include <map>
using namespace std;
```

#### **Syntax**

```cpp
map<string, int> m;
m["tv"] = 100;
m["laptop"] = 120;
```

---

#### **Key Properties**

* Elements are sorted by **key (ascending by default)**
* Each key is **unique**
* Implemented using **Red-Black Tree**

---

#### **Important Functions**

| Function                 | Description                          |
| ------------------------ | ------------------------------------ |
| `m[key] = value`         | Insert or update element             |
| `m.insert({key, value})` | Insert key-value pair                |
| `m.emplace(key, value)`  | Construct and insert (faster)        |
| `m.erase(key)`           | Erase element by key                 |
| `m.find(key)`            | Returns iterator to element or end() |
| `m.count(key)`           | Returns 1 if key exists, else 0      |
| `m.size()`               | Number of elements                   |
| `m.empty()`              | Check if empty                       |
| `m.clear()`              | Clear all elements                   |
| `m.begin()`, `m.end()`   | Iterators over map                   |

---

#### **Example**

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;

    m["tv"] = 100;
    m["laptop"] = 120;
    m.emplace("camera", 25);
    m.insert({"watch", 50});

    cout << "Map elements:\n";
    for (auto p : m)
        cout << p.first << " -> " << p.second << endl;

    cout << "Count of 'tv': " << m.count("tv") << endl;
    m.erase("watch");

    if (m.find("laptop") != m.end())
        cout << "'laptop' found" << endl;

    cout << "Map size: " << m.size();
}
```

**Output:**

```
Map elements:
camera -> 25
laptop -> 120
tv -> 100
watch -> 50
Count of 'tv': 1
'laptop' found
Map size: 3
```

---

#### **Other Map Types**

| Type            | Description                                                   |
| --------------- | ------------------------------------------------------------- |
| `multimap`      | Allows duplicate keys                                         |
| `unordered_map` | Stores data using hashing (not sorted, faster average access) |

---

### **B. Set**

#### **Definition**

A **set** stores **unique elements** in **sorted order**.

#### **Header File**

```cpp
#include <set>
using namespace std;
```

#### **Syntax**

```cpp
set<int> s = {10, 20, 10, 30}; // duplicates ignored
```

---

#### **Key Properties**

* Elements are **unique** and **sorted**
* Uses **balanced tree**
* Random access is not allowed
* Provides logarithmic time complexity for insert, erase, find

---

#### **Important Functions**

| Function           | Description                           |
| ------------------ | ------------------------------------- |
| `s.insert(x)`      | Insert element                        |
| `s.emplace(x)`     | Construct and insert                  |
| `s.erase(x)`       | Erase element                         |
| `s.count(x)`       | Check existence (1 if exists, else 0) |
| `s.find(x)`        | Returns iterator to element           |
| `s.size()`         | Number of elements                    |
| `s.empty()`        | Check if empty                        |
| `s.lower_bound(x)` | Iterator to first element >= x        |
| `s.upper_bound(x)` | Iterator to first element > x         |
| `s.clear()`        | Removes all elements                  |

---

#### **Example**

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.emplace(15);
    s.insert(20);

    cout << "Set elements: ";
    for (auto x : s) cout << x << " ";

    cout << "\nCount of 10: " << s.count(10);

    auto it = s.find(15);
    if (it != s.end())
        cout << "\nElement found: " << *it;

    s.erase(20);
    cout << "\nAfter erase: ";
    for (auto x : s) cout << x << " ";
}
```

**Output:**

```
Set elements: 10 15 20
Count of 10: 1
Element found: 15
After erase: 10 15
```

---

#### **Other Set Types**

| Type            | Description                                            |
| --------------- | ------------------------------------------------------ |
| `multiset`      | Allows duplicate elements                              |
| `unordered_set` | Unsorted, uses hash table (faster average O(1) access) |

---

### **Summary – Associative Containers**

| Container     | Duplicate | Order           | Implementation | Key-Value |
| ------------- | --------- | --------------- | -------------- | --------- |
| set           | No        | Sorted          | Tree           | No        |
| multiset      | Yes       | Sorted          | Tree           | No        |
| unordered_set | No        | Unsorted (Hash) | Hash Table     | No        |
| map           | No        | Sorted          | Tree           | Yes       |
| multimap      | Yes       | Sorted          | Tree           | Yes       |
| unordered_map | No        | Unsorted (Hash) | Hash Table     | Yes       |

---

Next part (Part 3) will cover:

### **3. Iterators**

### **4. Algorithms (sort, reverse, binary_search, max_element, etc.)**