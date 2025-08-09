
# **Python List (Equivalent to C++ Vector)**

---

## 1. **What is a Python List?**

A **list** in Python is an **ordered collection** of items that is **mutable** (we can change it after creating) and can store **different types of data** together.

For example:

```python
nums = [10, 20, 30]         # All integers
mixed = [1, "hello", 3.14]  # Mixed data types
```

**Key points:**

* Lists **grow and shrink dynamically** like C++ vectors.
* Lists allow **duplicate elements**.
* Lists keep the **order** of elements.

---

## 2. **How is it Different from C++ Vector?**

| Feature            | Python List                     | C++ Vector                      |
| ------------------ | ------------------------------- | ------------------------------- |
| Type restriction   | No (can store mixed data types) | Yes (stores only one data type) |
| Internal structure | Dynamic array                   | Dynamic array                   |
| Memory growth      | Increases gradually (\~1.125x)  | Usually doubles (2x)            |
| Performance        | Slower (dynamic typing)         | Faster                          |

---

## 3. **Creating Lists**

There are many ways to create a list:

### 3.1 Empty List

```python
lst = []
lst = list()
```

### 3.2 With Elements

```python
lst = [1, 2, 3, 4]
```

### 3.3 From Another Iterable

```python
lst = list(range(5))   # [0, 1, 2, 3, 4]
```

---

## 4. **Accessing Elements**

Lists use **zero-based indexing**:

```python
lst = [10, 20, 30, 40]
print(lst[0])    # First element: 10
print(lst[-1])   # Last element: 40
```

### Slicing

```python
lst[1:3]     # [20, 30] (from index 1 to 2)
lst[:2]      # [10, 20]
lst[::2]     # [10, 30] (every second element)
```

---

## 5. **Adding Elements**

| Method             | Description                      |
| ------------------ | -------------------------------- |
| `append(x)`        | Add element at the end           |
| `insert(i, x)`     | Insert `x` at index `i`          |
| `extend(iterable)` | Add multiple elements at the end |

Example:

```python
lst = [1, 2]
lst.append(3)          # [1, 2, 3]
lst.insert(1, 5)       # [1, 5, 2, 3]
lst.extend([6, 7])     # [1, 5, 2, 3, 6, 7]
```

---

## 6. **Removing Elements**

| Method      | Description                          |
| ----------- | ------------------------------------ |
| `pop()`     | Remove and return last element       |
| `pop(i)`    | Remove element at index `i`          |
| `remove(x)` | Remove first occurrence of value `x` |
| `clear()`   | Remove all elements                  |

Example:

```python
lst = [10, 20, 30]
lst.pop()        # Removes last → [10, 20]
lst.pop(0)       # Removes first → [20]
lst.remove(20)   # Removes value 20
```

---

## 7. **Searching and Checking**

* Check if an element exists:

```python
if 10 in lst:
    print("Found")
```

* Find index:

```python
lst = [1, 2, 3, 2]
print(lst.index(2))  # First index of 2 → 1
```

* Count occurrences:

```python
print(lst.count(2))  # Count of 2 → 2
```

---

## 8. **Other Useful Operations**

| Operation       | Example                  |
| --------------- | ------------------------ |
| Reverse list    | `lst.reverse()`          |
| Sort ascending  | `lst.sort()`             |
| Sort descending | `lst.sort(reverse=True)` |
| Sorted copy     | `sorted(lst)`            |
| Copy list       | `new_lst = lst.copy()`   |

---

## 9. **List Comprehension**

A short way to create lists:

```python
squares = [x*x for x in range(5)]  # [0, 1, 4, 9, 16]
```

With condition:

```python
even = [x for x in range(10) if x % 2 == 0]
```

---

## 10. **Nested Lists (Like 2D Vectors)**

```python
matrix = [[1, 2, 3], [4, 5, 6]]
print(matrix[0][1])  # Output: 2
```

---

## 11. **Internal Working (Memory Allocation)**

* Python lists are **dynamic arrays** internally.
* When you add elements and the list is full:

  * It **allocates a bigger block of memory**.
  * Copies old elements to the new memory.
  * The growth factor is about **1.125x** (in CPython).
* This makes `append()` **amortized O(1)**.

Example:

```python
lst = []
for i in range(100):
    lst.append(i)
```

This works without manually resizing because Python handles it internally.

---

## 12. **Time Complexity**

| Operation       | Complexity     |
| --------------- | -------------- |
| Access by index | O(1)           |
| Append          | O(1) amortized |
| Insert at start | O(n)           |
| Remove at start | O(n)           |
| Search          | O(n)           |

---

## 13. **Comparison with Other Python Data Structures**

* **List**: Good for general-purpose dynamic arrays.
* **Tuple**: Immutable list.
* **Set**: Unordered, no duplicates.
* **Deque (from collections)**: Faster for adding/removing at both ends.
* **NumPy Array**: For numerical operations and performance.

---

## 14. **Quick Summary Table**

| Function       | Purpose                                    |
| -------------- | ------------------------------------------ |
| `append(x)`    | Add element at end                         |
| `insert(i, x)` | Insert at position i                       |
| `extend(iter)` | Add multiple elements                      |
| `pop([i])`     | Remove element at i (or last if not given) |
| `remove(x)`    | Remove first occurrence of x               |
| `clear()`      | Remove all elements                        |
| `sort()`       | Sort list                                  |
| `reverse()`    | Reverse list                               |
| `copy()`       | Create a shallow copy                      |

---

## 15. **Where Lists are Used in Real Life**

* Storing dynamic data like student marks, user input.
* Implementing stacks and queues.
* Handling arrays for simple data processing tasks.

---