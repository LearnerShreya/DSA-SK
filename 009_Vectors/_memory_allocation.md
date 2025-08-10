# **Static vs Dynamic Memory Allocation in C++**

---

## **1. What is Memory Allocation?**

Memory allocation means **reserving space in RAM for variables or objects** during program execution.

There are **two main ways** to allocate memory in C++:

1. **Static Memory Allocation** → At **compile time**.
2. **Dynamic Memory Allocation** → At **run time**.

---

## **2. Static Memory Allocation**

* **Definition:** Memory is allocated **at compile time**, before the program runs.
* **Fixed size:** Once allocated, it **cannot be changed** during runtime.
* **Where stored:** **Stack** segment of memory.
* **Deallocation:** Done automatically when the variable goes out of scope.
* **How:** Using **normal variables, arrays, structures**.

---

### **Example of Static Memory Allocation**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;        // Static allocation
    int arr[5];        // Static array (size fixed at compile time)

    cout << "a = " << a << endl;
    return 0;
}
```

✔ Memory for `a` and `arr` is allocated at **compile time**.
✔ Cannot change the size of `arr` after declaration.

---

---

## **3. Dynamic Memory Allocation**

* **Definition:** Memory is allocated **at runtime**, as needed.
* **Flexible size:** You can decide size **during program execution**.
* **Where stored:** **Heap** segment of memory.
* **Deallocation:** Done **manually** using `delete` or `delete[]` (or `free()` in C).
* **How:** Using `new` and `delete` operators in C++ (or `malloc()` and `free()` in C).

---

### **Example of Dynamic Memory Allocation**

```cpp
#include <iostream>
using namespace std;

int main() {
    int* p = new int;   // Allocate memory for single int
    *p = 10;

    int* arr = new int[5]; // Allocate memory for array of 5 ints

    // Assign values dynamically
    for (int i = 0; i < 5; i++) arr[i] = i + 1;

    cout << "Single int: " << *p << endl;
    cout << "Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";

    delete p;        // Free single int
    delete[] arr;    // Free array
    return 0;
}
```

✔ Memory allocated on **heap**.
✔ We **must free memory manually**, else **memory leak** occurs.

---

---

## **4. Key Differences Between Static & Dynamic Memory Allocation**

| Feature             | Static Memory Allocation        | Dynamic Memory Allocation                  |
| ------------------- | ------------------------------- | ------------------------------------------ |
| **When allocated**  | **Compile time**                | **Runtime**                                |
| **Flexibility**     | Size fixed at compile time      | Size can be changed at runtime             |
| **Memory location** | **Stack**                       | **Heap**                                   |
| **Speed**           | Faster (no runtime overhead)    | Slower (due to runtime allocation)         |
| **Lifetime**        | Till variable goes out of scope | Till explicitly deallocated using `delete` |
| **Deallocation**    | Automatic                       | Manual (`delete`, `delete[]`)              |
| **Example**         | `int arr[10];`                  | `int* arr = new int[10];`                  |

---

---

## **When to Use Which?**

* **Static allocation:** When size is **known at compile time** and will not change.
* **Dynamic allocation:** When size is **unknown before program runs** or needs to change during execution.

---