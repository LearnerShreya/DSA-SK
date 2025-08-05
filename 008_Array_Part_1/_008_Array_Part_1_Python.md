
# Array Part 1

---

## 📘 **Array in Python**

### 1. **What is an Array?**

An **array** is a **collection of items** stored at **contiguous memory locations**. It allows storing **multiple items of the same data type** together under a single variable name.

In most programming languages (like C++), arrays have a fixed size and only hold one data type.
In Python, the built-in `list` is a more flexible data structure, but for true arrays (with fixed data types and more memory efficiency), Python provides the `array` module.

---

### 2. **Why Arrays?**

Without arrays:

```python
a1 = 5
a2 = 10
a3 = 15
```

Managing multiple related values becomes messy.

With arrays:

```python
arr = [5, 10, 15]
```

This makes storage, access, and operations on multiple elements easier and more efficient.

---

### 3. **Types of Arrays in Python**

| Type          | Description                                                           |
| ------------- | --------------------------------------------------------------------- |
| `list`        | Dynamic, can store mixed data types                                   |
| `array.array` | Static, stores elements of a single data type (more like C++ arrays)  |
| `numpy.array` | From NumPy library, faster and more powerful for scientific computing |

---

### 4. **Creating Arrays**

#### Using List:

```python
arr = [10, 20, 30, 40]
```

#### Using array module:

```python
import array
arr = array.array('i', [10, 20, 30, 40])  # 'i' = type code for signed integer
```

---

### 5. **Accessing Array Elements**

```python
print(arr[0])   # First element
print(arr[-1])  # Last element
```

* Indexing starts from 0.
* Negative indices access elements from the end.

---

### 6. **Traversing/Looping Through Arrays**

```python
# Using for loop
for num in arr:
    print(num)

# Using index
for i in range(len(arr)):
    print(arr[i])
```

---

### 7. **Basic Operations**

#### a. Input:

```python
arr = []
for i in range(5):
    val = int(input("Enter element: "))
    arr.append(val)
```

#### b. Output:

```python
print("Array elements:", arr)
```

#### c. Find Min & Max:

```python
print("Min:", min(arr))
print("Max:", max(arr))
```

#### d. Length of Array:

```python
print("Length:", len(arr))
```

---

### 8. **Searching in Array**

#### a. Linear Search (O(n)):

```python
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

index = linear_search([10, 20, 30], 20)
```

---

### 9. **Reversing an Array**

#### a. Using two-pointer approach:

```python
arr = [1, 2, 3, 4, 5]
start = 0
end = len(arr) - 1

while start < end:
    arr[start], arr[end] = arr[end], arr[start]
    start += 1
    end -= 1
```

#### b. Pythonic way:

```python
arr.reverse()
# or
reversed_arr = arr[::-1]
```

---

### 10. **Array Passed by Reference**

When you pass an array (or list) to a function, any changes inside the function will reflect on the original array.

```python
def modify(arr):
    arr[0] = 100

arr = [1, 2, 3]
modify(arr)
print(arr)  # Output: [100, 2, 3]
```

---

### 11. **Array vs List in Python**

| Feature      | List                | array.array                         |
| ------------ | ------------------- | ----------------------------------- |
| Type support | Multiple data types | Only one data type                  |
| Flexibility  | High                | Less                                |
| Performance  | Slower              | Faster (more memory-efficient)      |
| Use case     | General purpose     | Numeric data, memory-critical tasks |

---

### 12. **Array Algorithms You Should Know**

* **Traversal** – Loop through elements
* **Insertion** – At beginning, end, or specific index
* **Deletion** – By value or index
* **Search** – Linear or Binary (for sorted arrays)
* **Reversal** – Two-pointer or slicing
* **Sorting** – Bubble, Selection, Inbuilt `sort()`

---

### 13. **Homework Practice**

1. Write a function to find the second largest element.
2. Count the number of even and odd numbers in an array.
3. Reverse an array without using built-in functions.
4. Implement linear search and binary search.
5. Rotate an array by `k` steps.

---

### 14. **Bonus: Using NumPy Arrays (for Data Science)**

```python
import numpy as np
arr = np.array([1, 2, 3, 4])
print(arr * 2)   # Vectorized operation: [2 4 6 8]
```

* NumPy arrays are faster and used in ML/Data Science.
* They support broadcasting, vector operations, and consume less memory.

---

### Conclusion

* Arrays are fundamental for storing collections of data.
* Python offers flexible (`list`) and strict (`array.array`, `numpy.array`) options.
* Understanding how arrays work helps in solving problems related to data processing, memory management, and algorithm development.