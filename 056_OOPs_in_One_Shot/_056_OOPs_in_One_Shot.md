# OOPs in One Shot

---

### **Class & Object**

**Class**
A class is a blueprint of real-world entities.
Objects are entities in the real world.

---

### **Example: Teacher**

| **Teacher (entity)**                                    |
| ------------------------------------------------------- |
| **Properties (Attributes)**: name, age, subject, salary |
| **Method / Function**: changeDept()                     |

**Teacher (class) → Object → T1, T2, T3**

---

### **Example: Shop**

| **Shop (entity)**                                            |
| ------------------------------------------------------------ |
| **Properties (Attributes)**: name, price, category, discount |
| **Method / Function**: applyDiscount()                       |

**Shop (class) → Object → Obj 1, Obj 2, Obj 3**

---

### **Summary**

* **Class** = blueprint / template
* **Object** = real entity created from a class
* **Properties** = data/variables inside a class
* **Methods / Functions** = actions/behaviors inside a class

---
---

### **Class Syntax**

```
class className {
    // data members (attributes = properties = fields)
    // member functions (methods)
};
```

---

### **Access Modifier**

* **private (default):** data & methods accessible inside class.
* **protected:** data & methods accessible inside class & to its derived class.
* **public:** data & methods accessibility to everyone.

```cpp
#include <iostream>
using namespace std;

class Teacher {
private:
    double salary;
public:
    // properties / attributes
    string name;
    string dept;
    string subject;


    // methods / member functions
    void changeDept(string newDept) {
        dept = newDept;
    }

    // Setter for salary
    void setSalary(double s) {
        salary = s;
    }
    //Getter for salary
    double getSalary() {
        return salary;
    }
};


int main() {
    Teacher t1;
    Teacher t2;

    t1.name = "Shradha";
    t1.subject = "C++";
    t1.dept = "Computer Science";
    // t1.salary = 25000; // Error: 'salary' is private within this context
    t1.setSalary(25000);
    cout << t1.name << endl;
    cout << t1.getSalary() << endl;

    return 0;

}
```

---

### **OOPs – 4 Pillars**

1. **Abstraction**
2. **Inheritance**
3. **Polymorphism**
4. **Encapsulation**

---

### **Encapsulation**

Encapsulation is **wrapping up of data and member function in a single unit called a class**. It helps in data hiding.

```
Encapsulation = data members + member functions
```

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;       // data hiding
    string password;      // data hiding

public:
    string accountID;
    string username;

    // setter function
    void setData(double bal, string pass) {
        balance = bal;
        password = pass;
    }

    // getter function
    void getData() {
        cout << "Balance: " << balance << endl;
        cout << "Password: " << password << endl;
    }
};

int main() {
    BankAccount obj;
    obj.accountID = "AC123";
    obj.username = "Shreya";

    obj.setData(50000.0, "abc123"); // setting private data
    obj.getData();                  // accessing private data

    return 0;
}
```
---

### **Constructor**
Special method invoked automatically at the time of object creation. Used for initialization
* **Same name as class**
* **Constructor doesn’t have a return type**
* **Called only once (automatically) when object is created**
* **Memory allocation happens when constructor is called**

```cpp
#include <iostream>
using namespace std;

class Teacher {
private:
    double salary;          // private → hidden from outside the class

public:
    string name;
    string dept;
    string subject;
    string branch;

    // Constructor
    Teacher() {
        cout << "Hi, I am constructor" << endl;
        salary = 0;        // initialize private data
        branch = "CSE";
    }

    // Change department
    void changeDept(string newDept) {
        dept = newDept;
    }

    // Setter → write salary
    void setSalary(double s) {
        salary = s;
    }

    // Getter → read salary
    double getSalary() {
        return salary;
    }
};

int main() {
    Teacher t1;   // constructor called automatically
    Teacher t2;   // constructor called automatically

    t1.name = "Shradha";
    t1.subject = "C++";
    t1.dept = "Computer Science";
    t1.setSalary(25000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;
    cout << t1.branch << endl;

    return 0;
}
```

---

## `this` Pointer in C++

`this` is a special pointer inside a class that stores the address of the current calling object.

So,

```
this->prop   is same as   (*this).prop
```

It is mainly used when local variables and member variables have the same name.

### Example using `this` pointer

```cpp
#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    double salary;

public:
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

    string name;
    string dept;
    string subject;

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
    return 0;
}
```

---

## Copy Constructor in C++

A copy constructor creates a new object from an existing object.

Syntax:

```
ClassName(const ClassName &obj) { ... }
```

If you don’t write it yourself, C++ automatically provides a default copy constructor that performs shallow copy.

### Example (default + custom copy constructor)

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

    // parameterized constructor
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

    void getInfo() {
        cout << "name: " << this->name << endl;
        cout << "subject: " << this->subject << endl;
    }
};

int main() {
    Teacher t1("Shradha", "Computer Science", "C++", 25000);
    t1.getInfo();

    Teacher t2(t1); // default copy constructor called
    t2.getInfo();
    return 0;
}
```

---

## Shallow Copy vs Deep Copy

| Feature                              | Shallow Copy           | Deep Copy                 |
| ------------------------------------ | ---------------------- | ------------------------- |
| Pointer Variables                    | Copies pointer address | Allocates new memory      |
| If one object modifies pointer value | Other object affected  | Other object not affected |
| Speed                                | Fast                   | Slower                    |
| Safety                               | Unsafe                 | Safe                      |

---

### Shallow Copy Code

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

    // shallow copy constructor
    Student(const Student &obj) {
        this->name = obj.name;
        this->cgpaPtr = obj.cgpaPtr;  // pointer address copied (shared memory)
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1("rahul kumar", 8.9);
    cout << "Before modification:" << endl;
    s1.getInfo();

    Student s2(s1);      // shallow copy
    *(s2.cgpaPtr) = 9.2; // change in s2 affects s1 also

    cout << "\nAfter modifying s2.cgpaPtr:" << endl;
    s1.getInfo();        // CGPA changed here too
    s2.getInfo();

    return 0;
}
```

---

### Deep Copy Code

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

    // deep copy constructor
    Student(const Student &obj) {
        this->name = obj.name;
        cgpaPtr = new double;          // new memory allocation
        *cgpaPtr = *(obj.cgpaPtr);     // copying the actual value
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1("rahul kumar", 8.9);
    Student s2(s1);  // deep copy

    cout << "Before modification:" << endl;
    s1.getInfo();
    s2.getInfo();

    *(s2.cgpaPtr) = 9.2;   // modify only s2
    s2.name = "neha";

    cout << "\nAfter modifying s2:" << endl;
    s1.getInfo();          // no change in s1
    s2.getInfo();          // only s2 updated

    return 0;
}
```

---

## Final Quick Revision

| Topic                    | Meaning                                       |
| ------------------------ | --------------------------------------------- |
| `this` pointer           | Points to the current calling object          |
| Copy Constructor         | Creates a new object using an existing object |
| Default Copy Constructor | Performs shallow copy                         |
| Shallow Copy             | Copies pointer address (shared memory)        |
| Deep Copy                | Copies actual data (separate memory)          |

---

---

# Destructor in C++

## Definition

A destructor is a **special member function of a class** that is automatically invoked when an object is destroyed.
It is responsible for performing **cleanup operations** before the object is removed from memory.

---

## Syntax

```cpp
~ClassName() {
    // cleanup code
}
```

## Complete Example

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
---
---

## Inheritance

Inheritance allows a class to use the **properties and member functions of another class**.
It supports **code reusability**, reduces duplication, and improves maintainability.

Terminology:

* **Base / Parent class** → The class whose members are inherited.
* **Derived / Child class** → The class that receives the properties/functions of the base class.

---

## Basic Inheritance Example

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person() {
        cout << "Parent/Base constructor\n";
    }
};

class Student : public Person {
public:
    int rollno;

    Student() {
        cout << "Child/Derived constructor\n";
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Rollno: " << rollno << endl;
    }
};

int main() {
    Student s1;
    s1.name = "Rahul Kumar";
    s1.age = 21;
    s1.rollno = 123;

    s1.getInfo();
    return 0;
}
```

### Constructor & Destructor Call Order

* Constructor Order

  1. Base class
  2. Derived class

* Destructor Order

  1. Derived class
  2. Base class

---

## Constructor in Inheritance (Parameterized Constructor)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person {
public:
    int rollno;

    Student(string name, int age, int rollno) : Person(name, age) {
        this->rollno = rollno;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Rollno: " << rollno << endl;
    }
};

int main() {
    Student s1("Rahul Kumar", 21, 1234);
    s1.getInfo();
    return 0;
}
```

---

## Mode of Inheritance (Access Transformation Table)

| Member of Base Class | Public Mode → Derived | Protected Mode → Derived | Private Mode → Derived |
| -------------------- | --------------------- | ------------------------ | ---------------------- |
| Private              | Not inherited         | Not inherited            | Not inherited          |
| Protected            | Protected             | Protected                | Private                |
| Public               | Public                | Protected                | Private                |

---

## Types of Inheritance

### 1. Single Inheritance

```
Person  →  Student
```

```cpp
class Person { };
class Student : public Person { };
```

### 2. Multilevel Inheritance

```
Person → Student → GradStudent
```

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
};

class Student : public Person {
public:
    int rollno;
};

class GradStudent : public Student {
public:
    string researchArea;
};

int main() {
    GradStudent s1;
    s1.name = "Tony Stark";
    s1.researchArea = "Quantum Physics";

    cout << s1.name << endl;
    cout << s1.researchArea << endl;
    return 0;
}
```

### 3. Multiple Inheritance

```
Student  +  Teacher  →  TA
```

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollno;
};

class Teacher {
public:
    string subject;
    double salary;
};

class TA : public Student, public Teacher {
};

int main() {
    TA t1;
    t1.name = "Tony Stark";
    t1.subject = "Engineering";

    cout << t1.name << endl;
    cout << t1.subject << endl;
    return 0;
}
```

### 4. Hierarchical Inheritance

```
Person
|      |
Student Teacher
```

```cpp
class Person { };
class Student : public Person { };
class Teacher : public Person { };
```

### 5. Hybrid Inheritance (Combination)

```
        Person
      /        \
 Student      Teacher
      \       /
     GradStudent  TA
```

Hybrid = Combination of multiple inheritance + multilevel / hierarchical.

---

