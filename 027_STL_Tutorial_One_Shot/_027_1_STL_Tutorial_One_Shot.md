# STL Tutorial One Shot

---

## **1. STL Overview**

STL consists of 4 major components:

1. **Containers**
2. **Iterators**
3. **Algorithms**
4. **Functions**

---

## **2. Containers**

### **A. Sequence Containers**

#### **1. Vector (Dynamic Array)**

* **Initialization**

  ```cpp
  vector<int> vec;
  vector<int> vec = {1, 2};
  vector<int> vec(3, 10);
  vector<int> vec2(vec1);
  ```
* **Properties**

  * Dynamic resizing
  * Random access
* **Functions**

  * `size()`, `capacity()`
  * `push_back()`, `pop_back()`
  * `emplace_back()`
  * `at(index)` or `[]`
  * `front()`, `back()`
* **Modifiers**

  * `erase()`
  * `insert()`
  * `clear()`
  * `empty()`
* **Iterators**

  * `begin()`, `end()`

---

#### **2. List (Doubly Linked List)**

* **Initialization**

  ```cpp
  list<int> l = {1, 2, 3};
  ```
* **Functions**

  * `push_back()`, `push_front()`
  * `emplace_back()`, `emplace_front()`
  * `pop_back()`, `pop_front()`
  * `size()`, `erase()`, `clear()`
  * `begin()`, `end()`, `rbegin()`, `rend()`
  * `insert()`
  * `front()`, `back()`

---

#### **3. Deque (Double Ended Queue)**

* **Initialization**

  ```cpp
  deque<int> d = {1, 2, 3};
  ```
* **Functions**

  * `push_back()`, `push_front()`
  * `emplace_back()`, `emplace_front()`
  * `pop_back()`, `pop_front()`
  * `size()`, `erase()`, `clear()`
  * `begin()`, `end()`, `rbegin()`, `rend()`
  * `insert()`
  * `front()`, `back()`
* **Features**

  * Dynamic array structure
  * Supports random access

---

### **B. Container Adapters**

#### **1. Stack (LIFO)**

* **Initialization**

  ```cpp
  stack<int> s;
  ```
* **Functions**

  * `push()`, `emplace()`
  * `top()`
  * `pop()`
  * `size()`, `empty()`
  * `swap()`

---

#### **2. Queue (FIFO)**

* **Initialization**

  ```cpp
  queue<int> q;
  ```
* **Functions**

  * `push()`, `emplace()`
  * `front()`
  * `pop()`
  * `size()`, `empty()`
  * `swap()`

---

#### **3. Priority Queue**

* **Initialization**

  ```cpp
  priority_queue<int> q;  // Max Heap
  priority_queue<int, vector<int>, greater<int>> q;  // Min Heap
  ```
* **Functions**

  * `push()`, `emplace()`
  * `top()`
  * `pop()`
  * `size()`, `empty()`

---

### **C. Associative Containers**

#### **1. Map**

* **Initialization**

  ```cpp
  map<string, int> m;
  m[key] = value;
  ```
* **Functions**

  * `insert()`, `emplace()`
  * `count()`
  * `erase()`
  * `find()`
  * `size()`, `empty()`

##### **Other Maps**

* `multimap<string, int> m;`
* `unordered_map<string, int> m;`

---

#### **2. Set**

* **Initialization**

  ```cpp
  set<int> s;
  ```
* **Functions**

  * `insert()`, `emplace()`
  * `count()`
  * `erase()`
  * `find()`
  * `size()`, `empty()`
  * `lower_bound()`, `upper_bound()`

##### **Other Sets**

* `multiset<int> s;`
* `unordered_set<int> s;`

---

### **D. Utility Library**

#### **Pair**

* **Initialization**

  ```cpp
  pair<int, int> p = {3, 5};
  pair<char, int> p2 = {'a', 1};
  ```

---

## **3. Iterators**

* Used to point to container elements
* **Common Iterators**

  * `begin()`, `end()`
  * `rbegin()`, `rend()`

---

## **4. Algorithms (Header: <algorithm>)**

### **A. Sorting**

```cpp
sort(arr, arr + n);
sort(arr, arr + n, greater<int>());
sort(v.begin(), v.end());
```

---

### **B. Reverse**

```cpp
reverse(v.begin(), v.end());
```

---

### **C. Next Permutation**

```cpp
next_permutation(v.begin(), v.end());
```

---

### **D. Utility Functions**

```cpp
swap(a, b);
min(a, b);
max(a, b);
```

---

### **E. Max & Min Element**

```cpp
max_element(v.begin(), v.end());
min_element(v.begin(), v.end());
```

---

### **F. Binary Search**

```cpp
binary_search(v.begin(), v.end(), target);
```

---

### **G. Count Set Bits**

```cpp
__builtin_popcount(x);
__builtin_popcountl(x);
__builtin_popcountll(x);
```

---