# STL Tutorial One Shot

---

# **C++ STL One-Page Revision Sheet**

---

## **1. CONTAINERS**

### **Sequence Containers**

| Type       | Key Features                      | Example          |
| ---------- | --------------------------------- | ---------------- |
| **Vector** | Dynamic array, random access      | `vector<int> v;` |
| **List**   | Doubly linked list                | `list<int> l;`   |
| **Deque**  | Double-ended queue, random access | `deque<int> d;`  |

**Vector Functions:**
`push_back(), pop_back(), emplace_back(), insert(), erase(), clear(), empty(), size(), capacity(), front(), back(), at()`

**List/Deque Functions:**
`push_front(), push_back(), emplace_front(), emplace_back(), pop_front(), pop_back(), erase(), clear(), front(), back()`

---

### **Container Adaptors**

| Type               | Nature       | Functions                                                    |
| ------------------ | ------------ | ------------------------------------------------------------ |
| **Stack**          | LIFO         | `push(), emplace(), pop(), top(), size(), empty(), swap()`   |
| **Queue**          | FIFO         | `push(), emplace(), pop(), front(), size(), empty(), swap()` |
| **Priority Queue** | Max/Min heap | `push(), emplace(), pop(), top(), size(), empty()`           |

**Min Heap:**
`priority_queue<int, vector<int>, greater<int>> pq;`

---

### **Associative Containers**

| Type              | Features              | Example                        |
| ----------------- | --------------------- | ------------------------------ |
| **Map**           | Sorted by key         | `map<string,int> m;`           |
| **Multimap**      | Multiple same keys    | `multimap<string,int> m;`      |
| **Unordered Map** | Hash-based (unsorted) | `unordered_map<string,int> m;` |

**Common Functions:**
`insert(), emplace(), erase(), count(), find(), size(), empty()`

---

### **Set Containers**

| Type              | Features               | Example                 |
| ----------------- | ---------------------- | ----------------------- |
| **Set**           | Unique sorted elements | `set<int> s;`           |
| **Multiset**      | Duplicates allowed     | `multiset<int> s;`      |
| **Unordered Set** | Unique, unordered      | `unordered_set<int> s;` |

**Functions:**
`insert(), emplace(), erase(), count(), find(), size(), empty(), lower_bound(), upper_bound()`

---

## **2. ITERATORS**

| Type                       | Used In              | Movement       |
| -------------------------- | -------------------- | -------------- |
| **Input Iterator**         | Read stream          | Forward        |
| **Output Iterator**        | Write stream         | Forward        |
| **Forward Iterator**       | `unordered_map`      | Forward        |
| **Bidirectional Iterator** | `list`, `set`, `map` | Both           |
| **Random Access Iterator** | `vector`, `deque`    | +, -, indexing |

**Common Functions:**
`begin(), end(), rbegin(), rend(), cbegin(), cend()`

**Example:**

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it;
```

---

## **3. ALGORITHMS (<algorithm>)**

| Category               | Functions                                                       |
| ---------------------- | --------------------------------------------------------------- |
| **Sorting/Reordering** | `sort(), reverse(), next_permutation()`                         |
| **Searching**          | `binary_search(), find(), lower_bound(), upper_bound()`         |
| **Counting**           | `count(), count_if()`                                           |
| **Min/Max**            | `min(), max(), min_element(), max_element()`                    |
| **Utility**            | `swap(), accumulate(), fill(), replace(), unique(), distance()` |

**Examples:**

```cpp
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
binary_search(v.begin(), v.end(), x);
count(v.begin(), v.end(), val);
*max_element(v.begin(), v.end());
```

**Bit Count Functions (GCC Built-ins):**
`__builtin_popcount(x), __builtin_popcountl(x), __builtin_popcountll(x)`

---

## **4. FUNCTIONS & FUNCTORS**

### **Function Types**

| Type                          | Description                | Example                          |
| ----------------------------- | -------------------------- | -------------------------------- |
| **Normal Function**           | Defined using `bool cmp()` | `sort(v.begin(), v.end(), cmp)`  |
| **Function Pointer**          | Pass function as argument  | `sort(v.begin(), v.end(), &cmp)` |
| **Functor (Function Object)** | Object acting as function  | `greater<int>()`, `MyCompare()`  |
| **Lambda Function**           | Anonymous inline function  | `[](int a, int b){return a>b;}`  |
| **std::function**             | General function wrapper   | `function<int(int,int)> f;`      |

---

### **Predefined Functors (<functional>)**

| Functor             | Description |   |   |
| ------------------- | ----------- | - | - |
| `greater<T>()`      | a > b       |   |   |
| `less<T>()`         | a < b       |   |   |
| `plus<T>()`         | a + b       |   |   |
| `minus<T>()`        | a - b       |   |   |
| `multiplies<T>()`   | a * b       |   |   |
| `divides<T>()`      | a / b       |   |   |
| `equal_to<T>()`     | a == b      |   |   |
| `not_equal_to<T>()` | a != b      |   |   |
| `logical_and<T>()`  | a && b      |   |   |
| `logical_or<T>()`   | a           |   | b |
| `logical_not<T>()`  | !a          |   |   |

---

### **Lambda Quick Syntax**

```cpp
[capture](params) -> return_type { body; };

// Example
sort(v.begin(), v.end(), [](int a, int b){ return a > b; });
```

**Capture:**

* `[=]` all by value
* `[&]` all by reference
* `[=, &x]` all by value except x

---

### **std::function**

Can store **functions, lambdas, or functors**

```cpp
function<int(int,int)> add = [](int a, int b){return a+b;};
cout << add(3,4);
```

---

## **5. PRACTICE COMMANDS (Most Common)**

```cpp
// Vector
v.push_back(10); v.pop_back(); v.erase(v.begin()+2);

// Map
m["tv"] = 100; m.erase("tv"); if(m.count("tv")) cout<<"Exists";

// Set
s.insert(5); s.erase(5); s.find(3);

// Queue / Stack
q.push(1); q.pop(); s.top();

// Algorithm
sort(v.begin(), v.end(), greater<int>());
reverse(v.begin(), v.end());
cout << *max_element(v.begin(), v.end());
```

---

## **6. INTERVIEW KEY TAKEAWAYS**

* Prefer `auto` for iterators
* Always sort before using `binary_search()` or `lower_bound()`
* Use `unordered_map` / `unordered_set` for O(1) lookups
* Use `vector` over `list` for faster random access
* Lambdas are best for short custom comparators
* Functors are reusable and can maintain state
* STL algorithms always work on iterators, not directly on containers

---