# **Constructor Notes**

Constructor
├── Default Constructor
├── Parameterized Constructor
├── Copy Constructor
│   ├── Shallow Copy
│   └── Deep Copy
├── this Pointer
└── Destructor

## **Meaning**

A constructor is a **special member function of a class** that is **automatically executed when an object is created**.
Its main purpose is **to initialize the object** (give starting values to data members).

```
Constructor
    ├── Default Constructor
    ├── Parameterized Constructor
    ├── Copy Constructor
    │       ├── Default Copy Constructor      (compiler generated — always shallow)
    │       └── Custom Copy Constructor       (user defined)
    │               ├── Shallow Copy          (copies pointer addresses)
    │               └── Deep Copy             (allocates new memory and copies data)
    ├── Dynamic Constructor
    └── Conversion Constructor
```
#### **Copy Constructor**

```
Copy Constructor = Makes copy of an object
Default copy constructor = shallow copy
Custom copy constructor = can do deep copy
Called when new object initialized from existing object
```

---

## **Why Constructor is needed**

If no constructor is used, the object may contain **garbage / unassigned values**.
With a constructor, the object starts with **meaningful values** immediately after creation.

---

## **Important Characteristics**

1. **Same name as the class**
2. **No return type** (not even `void`)
3. **Called automatically at object creation**
4. **Executed only once per object**
5. **Memory for the object gets allocated when the constructor runs**
6. **Can be overloaded (multiple constructors with different parameters allowed)**

---

## **Who creates the constructor**

| Case                                    | Constructor created by | What happens                                                                  |
| --------------------------------------- | ---------------------- | ----------------------------------------------------------------------------- |
| Programmer writes a constructor         | Programmer             | Object initialized as per programmer’s code                                   |
| Programmer does NOT write a constructor | Compiler               | Default constructor generated → only creates object, no custom initialization |

---

## **Syntax**

```cpp
class ClassName {
public:
    ClassName() {        // constructor
        // initialization code
    }
};
```

---

## **Types of Constructors in C++**

| Type                          | Meaning                                          | Example call                  |
| ----------------------------- | ------------------------------------------------ | ----------------------------- |
| **Default Constructor**       | No parameters                                    | `ClassName obj;`              |
| **Parameterized Constructor** | Constructor contains parameters                  | `ClassName obj(10, "Aditi");` |
| **Copy Constructor**          | Creates new object by copying an existing object | `ClassName obj2 = obj1;`      |

*(Dynamic and Conversion constructors exist, but these three are most important for syllabus and interviews.)*

---

## **Example Showing All Three**

```cpp
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Default constructor
    Student() {
        cout << "Hi, I am constructor" << endl;
        name = "Unknown";
        age = 0;
    }

    // Parameterized constructor
    Student(string n, int a) {
        name = n;
        age = a;
    }

    // Copy constructor
    Student(Student &other) {
        name = other.name;
        age = other.age;
    }

    void show() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1;                    // Default
    Student s2("Aditi", 21);       // Parameterized
    Student s3 = s2;               // Copy

    s1.show();
    s2.show();
    s3.show();
}
```

Output:
```
Hi, I am constructor
Name: Unknown, Age: 0
Name: Aditi, Age: 21
Name: Aditi, Age: 21
```
---

## **Constructor Overloading**

More than one constructor in the same class with **different parameter list**. Constructor overloading is a part of polymorphism.

```cpp
Student();
Student(string);
Student(string, int);
```

Compiler chooses the constructor based on arguments passed during object creation.

---

## **Constructor vs Normal Function**

| Feature              | Constructor     | Normal Function       |
| -------------------- | --------------- | --------------------- |
| Name                 | Same as class   | Any name              |
| Return type          | No return type  | Must have return type |
| Called automatically | Yes             | No                    |
| Execution            | Once per object | Any number of times   |

---

## **Common Student Mistakes**

| Mistake                                             | Why wrong                                                                 |
| --------------------------------------------------- | ------------------------------------------------------------------------- |
| `void ClassName()`                                  | Constructors cannot have a return type                                    |
| Calling constructor manually like `obj.ClassName()` | Not allowed — runs automatically                                          |
| Copy constructor without reference `ClassName(obj)` | Causes infinite recursion, must use reference `ClassName(ClassName &obj)` |

---

## **One-line Revision**

> Constructor automatically initializes an object when it is created; same name as class, no return type, called once per object, and can be overloaded.

---

---

### **`this` Pointer**

* `this` is a **special pointer in C++ that stores the address of the current calling object**

* It helps differentiate between **local parameters and data members** when they have the same name inside a constructor or method

* Syntax:

  ```
  this->property
  ```

  is **same as**

  ```
  *(this).property
  ```

* When constructor parameters have the same name as class attributes, `this->` is used to assign values correctly:

  ```
  this->name = name;
  ```

  (left side is class property, right side is parameter)

* `this` pointer always points to the **object for which the constructor or method is executing**

* It is **automatically available** inside all non-static member functions and constructors

* It is **not available in static functions**, because static functions do not belong to any object

---
---

### **Copy Constructor**

* A **copy constructor** is a **special constructor** used to create a **new object as a copy of an existing object**.
* It **copies all the properties (data members)** from one object to another.

**General Syntax**

```
ClassName (ClassName &oldObj) {
    // copy statements
}
```

---

### **Why is Copy Constructor Needed? (Purpose)**

1. To **initialize a new object using an already existing object**
2. Very useful when an object has **pointers / dynamic memory** (deep copy)
3. To **avoid memory conflicts** in case of pointer members

---

### **Types of Copy Constructor in C++**

| Type                         | Created By                        | Behaviour                                                                      |
| ---------------------------- | --------------------------------- | ------------------------------------------------------------------------------ |
| **Default Copy Constructor** | Created by compiler automatically | Performs **shallow copy** (copies values bit-by-bit including pointer address) |
| **Custom Copy Constructor**  | Written by programmer             | Programmer decides how object is copied (deep copy possible)                   |

---

### **When Copy Constructor is Called Automatically?**

Copy constructor is invoked when:

1. Object is **created from another object**

```
Teacher t2(t1);
```

2. Object is **passed by value** to a function
3. Function **returns an object by value**

---

### **What Happens in Your Program**

```cpp
Teacher t2(t1);   // default copy constructor called
```

Because custom copy constructor is commented out, the compiler's **default copy constructor** is used.

**It performs a Shallow Copy**:

* Copies `name`, `dept`, `subject`, `salary` directly
* If there were pointers, both objects would share same memory

---

### **Key Properties of Copy Constructor**

* Object must be passed **by reference**

  ```
  Teacher (Teacher &obj)
  ```
* Must not return anything
* Object name and constructor name are same (just like any constructor)

---

### **Copy Constructor vs Assignment Operator**

| Feature   | Copy Constructor                | Assignment Operator (=)           |
| --------- | ------------------------------- | --------------------------------- |
| When used | New object created              | Object already exists             |
| Purpose   | Initialize object from existing | Replace values of existing object |
| Call      | `Teacher t2(t1);`               | `t2 = t1;`                        |

---

```cpp
#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // non-parameterized constructor
    Teacher() {
        dept = "Computer Science";
    }

    // parameterized constructor (using this pointer)
    Teacher(string name, string dept, string subject, double salary) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // custom copy constructor (optional)
    // Teacher(const Teacher &t) {
    //     cout << "I am custom copy constructor" << endl;
    //     this->name = t.name;
    //     this->dept = t.dept;
    //     this->subject = t.subject;
    //     this->salary = t.salary;
    // }

    void changeDept(string newDept) {
        this->dept = newDept;
    }

    void getInfo() {
        cout << "name: " << this->name << endl;
        cout << "subject: " << this->subject << endl;
    }
};

int main() {
    Teacher t1("Shradha", "Computer Science", "C++", 25000);
    t1.getInfo();

    Teacher t2(t1); // default copy constructor called (custom version is commented)
    t2.getInfo();

    return 0;
}
```

Output:
```
name: Shradha
subject: C++
name: Shradha
subject: C++
```

```
Teacher(const Teacher &t)
```

* `&` → without this, the object would be passed by value which triggers **another copy**, causing **infinite recursion**. So `&` stops the endless loop.
* `const` → allows reading the original object but **blocks modification** of it, and also allows copying **const objects**.

---
---

Here are the **same rewritten clear notes**, and your **provided codes are placed exactly in the correct section**, **without changing any line of code**.

---

# Shallow Copy & Deep Copy

---

## 1. Meaning of Copying an Object in OOP

When one object is created using another object, the system copies all data members from the source object to the new object.
If the class contains **pointers or dynamically allocated memory**, then copying can happen in two ways:

```
Shallow Copy → both objects share same memory
Deep Copy    → both objects have separate memory
```

---

## 2. Shallow Copy

### What it means

Shallow copy copies values **exactly as they are**.
If a member is a pointer, **only the pointer address is copied**, so both objects start pointing to **the same memory**.

### When it happens

Automatically through the **default copy constructor**, if the programmer does not define a custom copy constructor.

### Key mechanism line

```cpp
this->cgpaPtr = obj.cgpaPtr;
```

---

### Demonstrating Shallow Copy

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
        // cgpaPtr = new double;
        // *cgpaPtr = cgpa;
        cgpaPtr = new double(cgpa);
    }

    Student(const Student &obj) {
        this->name = obj.name;
        this->cgpaPtr = obj.cgpaPtr;   // shallow copy
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1("Rahul Kumar", 8.9);
    Student s2(s1);

    *(s2.cgpaPtr) = 9.2;  // modifies shared memory

    cout << "s1 details: " << endl;
    s1.getInfo();         // CGPA will become 9.2
    cout << "s2 details: " << endl;
    s2.getInfo();

    return 0;
}
```

### Behaviour

Updating CGPA from `s2` automatically updates `s1`, because both share the same memory.

---

## 3. Deep Copy

### What it means

Deep copy **allocates new memory** and copies the **value** from the original object.
So the new object does **not share memory** with the original object.

### Why it is needed

Required when a class uses:

* pointers
* dynamic memory allocation
* shared memory handles
  Without deep copy, modifying one object will affect the other and destructors will cause double-delete errors.

### Key mechanism line

```cpp
cgpaPtr = new double;
*cgpaPtr = *(obj.cgpaPtr);
```

---

### Demonstrating Deep Copy

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
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    Student(const Student &obj) {
        this->name = obj.name;
        // cgpaPtr = new double;            // deep copy
        // *cgpaPtr = *(obj.cgpaPtr);
        cgpaPtr = new double(*(obj.cgpaPtr));
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1("Rahul Kumar", 8.9);
    Student s2(s1);

    *(s2.cgpaPtr) = 9.2;   // modifies s2 only
    s2.name = "Neha";

    cout << "s1 details: " << endl;
    s1.getInfo();          // remains unchanged
    cout << "s2 details: " << endl;
    s2.getInfo();

    return 0;
}
```
#### all equivalent deep-copy value-copy styles
```
// *cgpaPtr = *obj.cgpaPtr;
// *cgpaPtr = *(obj.cgpaPtr);
// *(cgpaPtr) = *(obj.cgpaPtr);
// (*cgpaPtr) = *(obj.cgpaPtr);
// (*cgpaPtr) = *obj.cgpaPtr;
// cgpaPtr[0] = obj.cgpaPtr[0];
// cgpaPtr = new double(*obj.cgpaPtr);        // deep copy (allocate + copy value)
// cgpaPtr = new double(*(obj.cgpaPtr));      // deep copy (allocate + copy value)
```

### Behaviour

Updating CGPA or name from `s2` **does not** affect `s1`, because both objects have **separate memory**.

---

## 4. Shallow vs Deep — Quick Comparison

| Feature                 | Shallow Copy                       | Deep Copy                      |
| ----------------------- | ---------------------------------- | ------------------------------ |
| Pointer memory          | Shared                             | Separate                       |
| Extra memory allocation | No                                 | Yes                            |
| Risk                    | High (data overwrite, double free) | Safe                           |
| Performance             | Slightly faster                    | Slight overhead                |
| Recommended when        | No dynamic memory in class         | Dynamic memory exists in class |
| Use case                | Classes without pointers      | Classes with pointers / heap memory |
---

## 5. Final Summary

```
Shallow → ptr = obj.ptr          // both objects share memory
Deep    → ptr = new int(*obj.ptr)// both objects get separate memory
```

## Code Identifier

### Shallow

```cpp
Demo(const Demo &d) {
    ptr = d.ptr;
}
```

### Deep

```cpp
Demo(const Demo &d) {
    ptr = new int(*d.ptr);
}
```

```
Shallow → ptr = obj.ptr
Deep    → ptr = new int(*obj.ptr)
```

```
Shallow Copy
Object A ──► [ 10 ]
Object B ──┘    ▲   (shared memory)
```

```
Deep Copy
Object A ──► [ 10 ]
Object B ──► [ 10 ]   (separate memory)
```
```
* Shallow copy happens automatically (default copy constructor).
* Deep copy must be written manually (custom copy constructor).
```
* Shallow copy copies **pointer addresses**, so both objects share the same memory.
  Suitable only if the class does not use dynamic memory.
* Deep copy copies **data stored in memory into new memory**, so both objects are independent.
  Necessary for classes using pointers/dynamic memory to avoid data inconsistency and runtime errors.
---
---

# Destructor in C++

## 1. Definition

A destructor is a **special member function of a class** that is automatically invoked when an object is destroyed.
It is responsible for performing **cleanup operations** before the object is removed from memory.

---

## 2. Purpose

The main responsibility of a destructor is to release or clean up resources acquired by the object during its lifetime.
These resources may include:

* Dynamically allocated memory (created using `new`)
* File handles
* Network or database connections
* Any external resources associated with the object

If a destructor is not used when an object holds dynamic memory, that memory continues to remain occupied even after the object is gone. This leads to **memory leaks**.

---

## 3. Syntax

```cpp
~ClassName() {
    // cleanup code
}
```

Important points about syntax:

* Name must match the class name, with a tilde prefix (`~`)
* Never has a return type (not even void)
* Never takes parameters
* Cannot be overloaded (only one destructor per class)
* Cannot be declared `static`

---

## 4. When the Destructor is Called

A destructor is called automatically in these cases:

1. When an object goes out of scope (such as when a block ends)
2. When a dynamically allocated object is destroyed using `delete`
3. When a function returns and temporary objects are discarded
4. When the program terminates and remaining objects are cleaned up

The programmer does not need to manually call the destructor in normal cases.

---

## 5. Destructor and Dynamic Memory (The Most Important Role)

If the class has data members stored in **heap memory** using `new`, the destructor must use `delete` to release that memory.

Example of memory allocation in constructor:

```cpp
cgpaPtr = new double;
```

Matching deallocation in destructor:

```cpp
delete cgpaPtr;
```

Without this, the memory will never be released, causing memory leaks.

---

## 6. Complete Example

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
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
        cout << "Constructor called for " << name << endl;
    }

    ~Student() {
        delete cgpaPtr;
        cout << "Destructor called for " << name << endl;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main() {
    {
        Student s1("Rahul Kumar", 8.9);
        s1.getInfo();
    } // s1 goes out of scope here, destructor is automatically called

    return 0;
}
```

Explanation:

* Constructor allocates memory on heap using `new`
* Destructor frees the same memory using `delete`
* When the scope ends, object `s1` is destroyed and destructor executes automatically

---

## 7. Why Destructor Must Match `new` and `delete`

Constructors often allocate memory using `new`.
If the destructor does not free that memory using `delete`, the memory persists even after object destruction.

Correct pairing:

| Allocation | Deallocation |
| ---------- | ------------ |
| `new`      | `delete`     |
| `new[]`    | `delete[]`   |

Not following this rule is a major cause of memory leaks in C++.

---

## 8. Destructor and Copy Concepts

### Shallow Copy + Destructor

In shallow copy, two objects share the same pointer.
If destructor uses delete, both destructors try to delete the same memory → **double delete error** and program crash.

### Deep Copy + Destructor

In deep copy, each object has its own memory.
Destructor frees separate memory for each object → **safe and correct behaviour**.

Therefore, when a class contains dynamic memory:

* Constructor allocates memory
* Copy constructor must implement deep copy
* Destructor must free memory

This trio ensures safe memory management.

---

## 9. Final Key Points

* Destructor is a non-parameterized, non-returning member function that runs automatically at object destruction.
* Its primary purpose is to release dynamically allocated memory and external resources.
* Destructor cannot be overloaded and cannot be called manually under normal circumstances.
* In classes that use pointers or heap memory, destructor is essential to avoid memory leaks and undefined program behavior.

---
---

## Additional Notes on `delete`

`delete` is used in C++ to **free heap memory** that was previously allocated using `new`.
It does not delete the pointer variable itself. It only releases the memory that the pointer refers to.

### Why `delete` is required

Whenever memory is allocated using `new`, it remains reserved on the heap until it is explicitly released.
If `delete` is not used, that memory stays occupied even after the object is destroyed, which leads to **memory leaks**.

Example of correct pairing:

```cpp
cgpaPtr = new double;   // memory allocated in constructor
delete cgpaPtr;         // memory released in destructor
```

### Important points about `delete`

1. `delete` frees only the memory allocated by `new`
2. If `delete` is not written, the program may leak memory repeatedly
3. Do not use `delete` on memory that was not allocated using `new`
4. Do not apply `delete` twice to the same memory (double delete causes runtime crash)
5. After using `delete`, the pointer becomes invalid; assigning it to `nullptr` is good practice:

   ```cpp
   delete cgpaPtr;
   cgpaPtr = nullptr;
   ```

### Relationship between `new` and `delete`

| Task            | Used in                        | Reason                           |
| --------------- | ------------------------------ | -------------------------------- |
| Allocate memory | Constructor (or class methods) | To store values dynamically      |
| Release memory  | Destructor                     | To avoid memory leak and cleanup |

The correct lifecycle is:

* Constructor allocates heap memory using `new`
* Destructor frees heap memory using `delete`

This pairing ensures that every object manages its own lifetime safely and releases resources when no longer needed.

---