## **🔹 What is Copying an Object in C++?**

When one object is created from another, C++ copies **all data members** of the source object to the new object.

For simple variables (int, double, string, etc.) → value is copied safely.
For **pointers** → only the **address** may get copied unless handled carefully.

This creates two situations:

| Case         | What copies        | Result             |
| ------------ | ------------------ | ------------------ |
| Shallow Copy | Pointer address    | Memory shared      |
| Deep Copy    | New memory + value | Memory independent |

So the **entire confusion starts only when pointers or dynamic memory exist**.

---

Copy constructor is used when we need **a new object with the same data as an existing object**.

In real situations, it is helpful for:

* **Backup / snapshot of object state**
* **Undo / redo**
* **Temporary duplicate that will change independently**
* **Return or pass objects by value**
* **Copying objects into STL containers safely**

In one sentence:

> We use a copy constructor to clone an object **without sharing the same memory**, so both objects can change separately.

---

# **1) Shallow Copy**

Shallow copy copies **member-by-member**, including the **pointer address**.
Therefore, **two different objects point to the same heap memory**.

### **Key Behaviours**

* Only **one memory block** exists on the heap for pointer data
* Both objects behave as **one unit** for that pointer value
* Changing one modifies the other
* No new memory is allocated during copying

### **Advantages**

* Fast and simple
* No extra memory usage

### **Disadvantages**

* **Unsafe** because objects interfere with each other
* **Double delete problem** if destructors are used (both try to free same memory)

### **Shallow Copy Code with Comments**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    double* cgpaPtr;

    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double(cgpa); // memory created once
    }

    // Shallow Copy Constructor
    Student(const Student &obj) {
        this->name = obj.name;
        this->cgpaPtr = obj.cgpaPtr; // address copied → shared memory
    }
};

int main() {
    Student s1("Rahul", 8.9);
    Student s2(s1);                // shallow copy

    *(s2.cgpaPtr) = 9.5;           // modify s2 cgpa

    cout << *s1.cgpaPtr << endl;   // 9.5 → changed
    cout << *s2.cgpaPtr << endl;   // 9.5
}
```

### **Memory Diagram (Shallow)**

```
                +------------------+
s1 ------------>| name = Rahul     |
                | cgpaPtr ---------|-----+
                +------------------+     |
                                          v
                                     +---------+
                                     | 8.9     |
                                     +---------+
                +------------------+     ▲
s2 ------------>| name = Rahul     |     |
                | cgpaPtr ---------|-----+
                +------------------+
```

**One pointer value shared by both → unsafe**

---

# **2) Deep Copy**

Deep copy handles pointer members **safely** by allocating **separate memory** and copying the **value only**, not the address.

### **Key Behaviours**

* New memory allocated on heap for copied object
* Objects become **fully independent**
* Any modification to one does **not affect the other**

### **Advantages**

* Safe and reliable
* No interference between objects
* No double delete issues

### **Disadvantages**

* Slightly slower (extra memory allocation)
* More code to write

### **Deep Copy Code with Comments**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    double* cgpaPtr;

    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double(cgpa);  // memory created for s1
    }

    // Deep Copy Constructor
    Student(const Student &obj) {
        this->name = obj.name;
        cgpaPtr = new double(*(obj.cgpaPtr));   // new memory + same value
    }
};

int main() {
    Student s1("Rahul", 8.9);
    Student s2(s1);                      // deep copy

    *(s2.cgpaPtr) = 9.5;                 // modify s2 only

    cout << *s1.cgpaPtr << endl;         // 8.9 → unchanged
    cout << *s2.cgpaPtr << endl;         // 9.5
}
```

### **Memory Diagram (Deep)**

```
                +------------------+
s1 ------------>| name = Rahul     |
                | cgpaPtr ---------|------+
                +------------------+      |
                                           v
                                      +---------+
                                      | 8.9     |
                                      +---------+

                +------------------+
s2 ------------>| name = Rahul     |
                | cgpaPtr ---------|------+
                +------------------+      |
                                           v
                                      +---------+
                                      | 8.9     | ← later becomes 9.5 only for s2
                                      +---------+
```

**Separate memory for both → safe**

---

## **Complete Comparison Table**

| Feature               | Shallow Copy  | Deep Copy        |
| --------------------- | ------------- | ---------------- |
| Pointer address       | Copied        | Not copied       |
| Memory                | Shared        | Separate         |
| Speed                 | Fast          | Slightly Slower  |
| Safety                | Unsafe        | Safe             |
| Memory usage          | Low           | Higher           |
| When pointer modified | Affects both  | Affects only one |
| Destructor risk       | Double delete | No problem       |

---

## **When to Use Which**

| Situation                                   | Recommended            |
| ------------------------------------------- | ---------------------- |
| Class has no pointer or dynamic memory      | Shallow copy is enough |
| Class contains pointers or allocated memory | Deep copy required     |
| Safety & reliability needed                 | Deep copy              |
| Performance critical and no pointer use     | Shallow copy           |

---

## **One Ultimate Line to Remember**

> Shallow copy copies **address**, while deep copy copies **value and memory**.

---

### 🔹 Where variables are stored in C++

| Type of allocation                   | Where stored | Created when             | Destroyed when                 |
| ------------------------------------ | ------------ | ------------------------ | ------------------------------ |
| Static / Global variables            | Data Segment | Program start            | Program end                    |
| Local variables                      | Stack        | Function call            | Function exit                  |
| **Dynamic memory** (`new`, `malloc`) | **Heap**     | Runtime / when requested | When `delete` / `free` is used |

---

### 🔹 Why dynamic memory = heap

Because:

* It is **not fixed size**
* It **stays in memory even after function ends**
* Lifetime is **controlled by programmer**

Example:

```cpp
int *p = new int(10);
```

Here:

* `p` is stored on **stack**
* `new int(10)` reserves memory on **heap**
* That memory will remain until `delete p` is called

---

### 🔹 If you don’t delete heap memory

It becomes **memory leak**, meaning memory remains allocated and unavailable even though no longer needed.

```cpp
delete p;    // frees heap memory
```

---