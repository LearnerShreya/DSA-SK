# Vectors


## 1. **What is a Vector?**

A **vector** is a container in C++ that stores a collection of elements in a **dynamic array**. Unlike normal arrays in C++ (which have a fixed size), vectors can **grow and shrink automatically** when elements are added or removed.

It is part of the **Standard Template Library (STL)** and is defined in the header file:

```cpp
#include <vector>
```

All vector-related features are inside the `std` namespace, so you either use `std::vector` or `using namespace std;`.

---

## 2. **Why use a Vector instead of an Array?**

* Arrays in C++ have a **fixed size**, which you must know at compile time. You cannot change their size later.
* Vectors manage their **own memory**. They automatically resize when needed.
* Vectors provide **built-in functions** for adding, removing, and accessing elements.
* Vectors allow **random access** to elements (like arrays) in constant time.
* They work well with STL algorithms such as `sort`, `find`, `count`, etc.

---

## 3. **Basic Syntax**

To declare a vector:

```cpp
vector<data_type> vector_name;
```

Examples:

```cpp
vector<int> v;          // An empty vector of integers
vector<int> v(5);       // Vector of size 5 with default values (0 for int)
vector<int> v(5, 10);   // Vector of size 5 with all values as 10
vector<int> v = {1,2,3}; // Initialize with values
```

---

## 4. **Common Operations**

Here are the most used operations:

| Operation             | Description                              |
| --------------------- | ---------------------------------------- |
| `push_back(x)`        | Add element `x` at the end               |
| `pop_back()`          | Remove last element                      |
| `size()`              | Return number of elements in the vector  |
| `capacity()`          | Return current allocated memory capacity |
| `empty()`             | Check if vector is empty                 |
| `clear()`             | Remove all elements                      |
| `insert(position, x)` | Insert element at specific position      |
| `erase(position)`     | Remove element at specific position      |
| `swap(v1, v2)`        | Swap contents of two vectors             |

---

### Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Size: " << v.size() << endl; // Output: 3

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.pop_back();
    cout << "After pop_back(): ";
    for(int x : v) {
        cout << x << " ";
    }
}
```

---

## 5. **Ways to Initialize a Vector**

1. Empty vector:

   ```cpp
   vector<int> v;
   ```
2. With size:

   ```cpp
   vector<int> v(5); // {0, 0, 0, 0, 0}
   ```
3. With size and initial value:

   ```cpp
   vector<int> v(5, 10); // {10, 10, 10, 10, 10}
   ```
4. From another vector:

   ```cpp
   vector<int> v1 = {1, 2, 3};
   vector<int> v2(v1);
   ```
5. From an array:

   ```cpp
   int arr[] = {1, 2, 3};
   vector<int> v(arr, arr + 3);
   ```

---

## 6. **Accessing Elements**

* Using index:

  ```cpp
  cout << v[0];
  ```
* Using `at()` (throws error if out of range):

  ```cpp
  cout << v.at(0);
  ```
* First and last element:

  ```cpp
  cout << v.front(); // First element
  cout << v.back();  // Last element
  ```

---

## 7. **Capacity Functions**

Vectors maintain two properties:

* **Size**: Actual number of elements in the vector.
* **Capacity**: The amount of memory allocated (may be larger than size).

Common functions:

* `size()`: Returns current size
* `capacity()`: Returns current allocated memory
* `resize(n)`: Change size to `n`
* `reserve(n)`: Pre-allocate memory for `n` elements
* `shrink_to_fit()`: Reduce capacity to match size
* `empty()`: Check if vector has no elements

Example:

```cpp
vector<int> v;
v.push_back(1);
v.push_back(2);
cout << v.size();     // 2
cout << v.capacity(); // May be 4 (depends on system)
```

---

## 8. **Iterators in Vector**

An **iterator** is like a pointer that helps to traverse through the vector.

* `begin()` → First element
* `end()` → One position after the last element
* `rbegin()` → Last element (reverse begin)
* `rend()` → One position before the first element (reverse end)

Example:

```cpp
vector<int> v = {10, 20, 30};

for(auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```

Types of iterators:

* `iterator` (normal read/write)
* `const_iterator` (read-only)
* `reverse_iterator`

---

## 9. **Insert and Erase**

* Insert:

  ```cpp
  v.insert(v.begin() + 1, 99); // Insert 99 at position 1
  ```
* Erase:

  ```cpp
  v.erase(v.begin() + 2); // Remove element at index 2
  ```

---

## 10. **How Vectors Manage Memory**

When you add elements to a vector, if the current capacity is full, the vector **doubles its capacity** (or increases by a certain growth factor). This means:

* Insert at the end is usually **O(1)** time, but occasionally **O(n)** when resizing occurs (amortized O(1)).
* Removing elements from the middle shifts elements, which takes **O(n)** time.

---

## 11. **Time Complexity Summary**

| Operation              | Complexity     |
| ---------------------- | -------------- |
| Access by index        | O(1)           |
| Add element at end     | O(1) amortized |
| Insert/Erase in middle | O(n)           |
| Search                 | O(n)           |

---

## 12. **Advanced Usage**

* Vector of Vectors (2D Vector):

  ```cpp
  vector<vector<int>> matrix = {{1,2}, {3,4}};
  ```
* Sort a vector:

  ```cpp
  sort(v.begin(), v.end());
  ```
* Sort in descending:

  ```cpp
  sort(v.begin(), v.end(), greater<int>());
  ```
* Remove duplicates:

  ```cpp
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  ```

---

## 13. **Important Points**

* Vectors always store elements in **contiguous memory locations** like arrays.
* If you insert or erase in the middle often, `list` or `deque` might be better.
* Passing a vector to a function by value copies it (costly). Use reference:

  ```cpp
  void func(vector<int> &v);
  ```
* If you know the number of elements beforehand, use `reserve()` to avoid multiple reallocations.

---

## 14. **Common Interview Questions**

* Explain `size()` vs `capacity()`.
* Why is `push_back()` amortized O(1)?
* How to delete duplicates from a vector?
* How does vector handle memory internally?
* Difference between `vector` and `array`?

---