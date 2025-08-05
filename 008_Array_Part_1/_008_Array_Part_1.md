
# Array Part 1

---

# **Array – Complete Notes**

## **1. Introduction to Arrays**

### **What is an Array?**

An array is a **linear data structure** used to store elements of **homogeneous (same) data types** in **contiguous memory locations**. Each element in the array can be accessed directly using its index.

### **Why Arrays?**

Before arrays, if we wanted to store multiple values (e.g., 100 integers), we would have to declare 100 different variables. Arrays solve this problem by allowing us to group similar elements under a single name, making the code more organized and efficient.

### **Example:**

```cpp
int arr[5] = {10, 20, 30, 40, 50};
```

Here, `arr` is an integer array of size 5 containing five integer elements.

---

## **2. Characteristics of Arrays**

* **Fixed Size**: Once declared, the size of an array cannot be changed.
* **Index-based Access**: Elements are accessed using indices starting from 0 to size-1.
* **Contiguous Memory Allocation**: Elements are stored in consecutive memory locations.
* **Homogeneous Elements**: All elements in an array must be of the same data type.

---

## **3. Declaration and Initialization**

### **Declaration:**

```cpp
datatype arrayName[size];
```

Example:

```cpp
int arr[10];
```

### **Initialization:**

```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

Partial Initialization:

```cpp
int arr[5] = {1, 2};  // Remaining values will be set to 0
```

Compiler-Inferred Size:

```cpp
int arr[] = {10, 20, 30};  // Size is 3
```

---

## **4. Accessing Elements**

Array elements are accessed using an index.

```cpp
cout << arr[0];  // Accesses the first element
arr[2] = 50;     // Updates the third element
```

**Note**: Accessing out-of-bound indices leads to **undefined behavior** in C++.

---

## **5. Input and Output**

### **Input:**

```cpp
for (int i = 0; i < n; i++) {
    cin >> arr[i];
}
```

### **Output:**

```cpp
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
```

---

## **6. Size of Array**

```cpp
int arr[10];
int size = sizeof(arr) / sizeof(arr[0]);  // Works only for local/static arrays
```

**Note**: For arrays passed to functions, this method will not work as they decay into pointers.

---

## **7. Memory Layout**

In memory, an array like:

```cpp
int arr[4] = {10, 20, 30, 40};
```

is stored as:

```
Index:    0     1     2     3
Value:   10    20    30    40
```

Each integer typically takes 4 bytes (on 64-bit systems).

---

## **8. Array Operations**

### a) **Linear Search**

```cpp
int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}
```

**Time Complexity**: O(n)

---

### b) **Finding Maximum and Minimum**

```cpp
int min = arr[0];
int max = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] < min) min = arr[i];
    if (arr[i] > max) max = arr[i];
}
```

**Time Complexity**: O(n)

---

### c) **Reversing an Array (Two-Pointer Technique)**

```cpp
void reverse(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
```

**Time Complexity**: O(n)
**Space Complexity**: O(1) (in-place)

---

## **9. Pass by Reference Behavior**

In C++, arrays are passed by reference to functions.

```cpp
void change(int arr[]) {
    arr[0] = 100;
}
```

Calling `change(arr);` will modify the original array.

This is because arrays decay into pointers when passed to functions, so changes reflect in the original memory.

---

## **10. Limitations of Arrays**

* Fixed size (not resizable at runtime)
* Only homogeneous data types allowed
* Insertion/deletion is expensive (O(n))
* No inbuilt bounds checking

---

## **11. Types of Arrays**

### a) **One-dimensional Array**

```cpp
int arr[5];
```

### b) **Two-dimensional Array (Matrix)**

```cpp
int matrix[3][3];
```

### c) **Multidimensional Array**

```cpp
int tensor[3][4][2];  // 3D array
```

---

## **12. Applications of Arrays**

* Storing data sequences like scores, heights, ages, etc.
* Used in implementing other data structures like stacks, queues, matrices.
* Basis for solving problems in searching, sorting, dynamic programming.
* Efficient memory access via indexing.
* Used in algorithm design, graphics, and simulations.

---

## **13. Difference: Array vs Pointer**

| Feature           | Array                 | Pointer                         |
| ----------------- | --------------------- | ------------------------------- |
| Memory allocation | Fixed at compile time | Dynamic at runtime (via malloc) |
| Access method     | Using index           | Using pointer arithmetic        |
| Modifiability     | Name not modifiable   | Pointer can be reassigned       |

---

## **14. Array in Memory (Pointer Relation)**

```cpp
int arr[5] = {10, 20, 30, 40, 50};
cout << *arr;        // Prints 10
cout << *(arr + 1);  // Prints 20
```

Arrays are closely related to pointers. `arr` is equivalent to `&arr[0]`.

---

## **15. Important Interview Questions**

1. Reverse an array in-place.
2. Find the maximum/minimum element.
3. Check if an array is sorted.
4. Remove duplicates from sorted/unsorted array.
5. Rotate array by k positions.
6. Find the second largest element.
7. Count frequency of each element.
8. Merge two sorted arrays.

---

## **Conclusion**

Arrays are the most fundamental data structure that form the basis for understanding memory organization, algorithmic thinking, and advanced data structures. Despite their limitations, arrays are powerful when used efficiently and are essential for mastering DSA and clearing technical interviews.

---