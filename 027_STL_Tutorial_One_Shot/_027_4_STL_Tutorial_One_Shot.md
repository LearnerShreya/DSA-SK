# STL Tutorial One Shot

---

# **Part 3: Iterators and Algorithms in STL**

---

## **1. Iterators**

### **1.1 What are Iterators?**

Iterators act like pointers used to access elements of STL containers.
They help traverse containers like `vector`, `list`, `set`, `map`, etc., without knowing the internal structure.

You can think of them as a **bridge between containers and algorithms.**

---

### **1.2 Types of Iterators**

| Iterator Type              | Supported Containers                  | Movement                          | Access       | Example                        |
| -------------------------- | ------------------------------------- | --------------------------------- | ------------ | ------------------------------ |
| **Input Iterator**         | `istream_iterator`, single-pass read  | Forward                           | Read-only    | Reading data from input stream |
| **Output Iterator**        | `ostream_iterator`, single-pass write | Forward                           | Write-only   | Writing data to output stream  |
| **Forward Iterator**       | `forward_list`, `unordered_map`       | Forward                           | Read & Write | Traversing singly linked list  |
| **Bidirectional Iterator** | `list`, `set`, `map`                  | Forward & Backward                | Read & Write | Traversing in both directions  |
| **Random Access Iterator** | `vector`, `deque`, `array`            | Forward, Backward, +, -, indexing | Read & Write | Works like normal pointers     |

---

### **1.3 Common Iterator Functions**

| Function   | Description                                          | Example        |
| ---------- | ---------------------------------------------------- | -------------- |
| `begin()`  | Points to the first element                          | `vec.begin()`  |
| `end()`    | Points to **one past the last** element              | `vec.end()`    |
| `rbegin()` | Points to the last element (reverse begin)           | `vec.rbegin()` |
| `rend()`   | Points to **before the first** element (reverse end) | `vec.rend()`   |
| `cbegin()` | Constant iterator to beginning (read-only)           | `vec.cbegin()` |
| `cend()`   | Constant iterator to end (read-only)                 | `vec.cend()`   |

---

### **1.4 Syntax Example (Vector)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    // Using iterator
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";

    cout << endl;

    // Using reverse iterator
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit)
        cout << *rit << " ";
}
```

**Output:**

```
10 20 30 40 50
50 40 30 20 10
```

---

### **1.5 Key Points**

* `*it` is used to access the value iterator points to.
* `it++` moves to the next element.
* `--it` moves to the previous element (only for bidirectional/random access iterators).
* Use `auto` to simplify code.
* Random access iterators support arithmetic like `it + 2`, `it - 1`, etc.

---

### **1.6 Iterator with List**

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {1, 2, 3, 4};

    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
}
```

**Output:**

```
1 2 3 4
```

Note: You **cannot use random access** like `it + 2` with list iterators.

---

### **1.7 Constant and Reverse Iterators Example**

```cpp
for (auto it = vec.cbegin(); it != vec.cend(); ++it)
    cout << *it << " "; // Read-only

for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit)
    cout << *rit << " "; // Reverse order
```

---

### **1.8 Iterator Functions with Algorithms**

Iterators are often passed to algorithms like `sort`, `reverse`, `find`, etc.

```cpp
sort(vec.begin(), vec.end());
reverse(vec.begin(), vec.end());
find(vec.begin(), vec.end(), 20);
```

---

## **2. Algorithms in STL**

### **2.1 Introduction**

The **<algorithm>** header provides a huge set of pre-defined functions that perform operations on containers.
These include sorting, searching, counting, reversing, rotating, etc.

Algorithms are **template-based** and work with **iterators**.

---

### **2.2 Classification of Algorithms**

| Category                   | Example Functions                                             |
| -------------------------- | ------------------------------------------------------------- |
| **Sorting and Reordering** | `sort()`, `reverse()`, `rotate()`, `next_permutation()`       |
| **Searching**              | `binary_search()`, `find()`, `lower_bound()`, `upper_bound()` |
| **Counting**               | `count()`, `count_if()`                                       |
| **Min/Max**                | `min()`, `max()`, `min_element()`, `max_element()`            |
| **Others**                 | `swap()`, `accumulate()`, `fill()`, `replace()`               |

---

### **2.3 Sorting**

#### **Syntax:**

```cpp
sort(start_iterator, end_iterator);
sort(start_iterator, end_iterator, greater<int>());
```

#### **Example:**

```cpp
vector<int> v = {5, 1, 4, 2, 3};
sort(v.begin(), v.end());
for (auto x : v) cout << x << " ";
```

**Output:**

```
1 2 3 4 5
```

#### **Descending Order:**

```cpp
sort(v.begin(), v.end(), greater<int>());
```

---

### **2.4 Reverse**

Reverses the order of elements.

```cpp
reverse(v.begin(), v.end());
```

---

### **2.5 Next Permutation**

Gives the next lexicographically greater permutation.

```cpp
vector<int> v = {1, 2, 3};
next_permutation(v.begin(), v.end());
```

**Output:** `1 3 2`

If already at the last permutation, it becomes the first.

---

### **2.6 Min and Max**

#### **Syntax:**

```cpp
cout << min(4, 9);
cout << max(6, 10);
```

#### **For Containers:**

```cpp
vector<int> v = {3, 1, 5, 2};
cout << *max_element(v.begin(), v.end()); // 5
cout << *min_element(v.begin(), v.end()); // 1
```

---

### **2.7 Binary Search**

Used for checking if an element exists in a sorted array or vector.

```cpp
vector<int> v = {1, 2, 3, 4, 5};
bool found = binary_search(v.begin(), v.end(), 3);
if (found) cout << "Present";
else cout << "Absent";
```

---

### **2.8 Lower Bound and Upper Bound**

Both require a **sorted container**.

| Function        | Returns                                |
| --------------- | -------------------------------------- |
| `lower_bound()` | Iterator to first element **>= value** |
| `upper_bound()` | Iterator to first element **> value**  |

```cpp
vector<int> v = {1, 2, 4, 4, 5};
cout << (lower_bound(v.begin(), v.end(), 4) - v.begin()); // 2
cout << (upper_bound(v.begin(), v.end(), 4) - v.begin()); // 4
```

---

### **2.9 Count and Count_if**

```cpp
vector<int> v = {1, 2, 3, 2, 2, 5};
cout << count(v.begin(), v.end(), 2); // 3
```

Using condition:

```cpp
cout << count_if(v.begin(), v.end(), [](int x){ return x > 2; });
```

---

### **2.10 Swap**

```cpp
int a = 5, b = 10;
swap(a, b);
```

Or between vectors:

```cpp
swap(v1, v2);
```

---

### **2.11 Count Set Bits**

Used with GCC built-in functions:

| Function                  | Description                 |
| ------------------------- | --------------------------- |
| `__builtin_popcount(x)`   | Count set bits in int       |
| `__builtin_popcountl(x)`  | Count set bits in long      |
| `__builtin_popcountll(x)` | Count set bits in long long |

```cpp
int x = 9; // 1001
cout << __builtin_popcount(x); // Output: 2
```

---

### **2.12 Other Useful Algorithms**

| Function       | Purpose                        | Example                                 |
| -------------- | ------------------------------ | --------------------------------------- |
| `accumulate()` | Sum of all elements            | `accumulate(v.begin(), v.end(), 0)`     |
| `fill()`       | Fill all elements with a value | `fill(v.begin(), v.end(), 0)`           |
| `replace()`    | Replace values                 | `replace(v.begin(), v.end(), old, new)` |
| `unique()`     | Remove consecutive duplicates  | `unique(v.begin(), v.end())`            |
| `distance()`   | Distance between two iterators | `distance(v.begin(), it)`               |

---

## **3. Summary Table**

| Algorithm              | Description                      |
| ---------------------- | -------------------------------- |
| `sort()`               | Sort elements                    |
| `reverse()`            | Reverse order                    |
| `next_permutation()`   | Next lexicographical permutation |
| `min_element()`        | Minimum element                  |
| `max_element()`        | Maximum element                  |
| `binary_search()`      | Check presence of element        |
| `lower_bound()`        | First position >= value          |
| `upper_bound()`        | First position > value           |
| `count()`              | Frequency count                  |
| `__builtin_popcount()` | Count set bits                   |

---
