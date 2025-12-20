# INHERITANCE IN C++

## 1. Concept and Definition

Inheritance is an OOP mechanism / feature that allows a **new class (derived/child)** to be created from an **existing class (base/parent)**.
The derived class automatically receives the base class’s **data members and member functions**. It enables code reuse, standardization, and scalability in software design.

```
Derived class = Base class features + New additional features
```

In simple words:
The purpose is reuse of existing code rather than writing the same variables and functions again in multiple classes.

## Basic Example Showing Reusability

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
};

class Student : public Person {  // inheritance done here
public:
    int rollno;
};

int main() {
    Student s;
    s.name = "Rahul";
    s.age = 21;
    s.rollno = 101;

    cout << s.name << endl;
    cout << s.age << endl;
    cout << s.rollno << endl;
    return 0;
}
```

### **Output**

```
Rahul
21
101
```

Without inheritance, the Student class would also need `name` and `age`.
With inheritance, Student automatically receives them from Person.

---

## 2. Why Inheritance Exists in OOP

### 2.1 Code Reusability

Avoids rewriting shared logic (e.g., name, age, address, print details) in every class.

### 2.2 Logical Modeling of Real World

Real-world classification naturally fits inheritance.
Example: A student is a specific case of a person.

### 2.3 Maintainability

If a change occurs in the base implementation, all derived classes automatically reflect it.

### 2.4 Extensibility

Existing classes can be extended with new functionality instead of modifying original code.

---

| Without Inheritance   | With Inheritance          |
| --------------------- | ------------------------- |
| Code repetition       | No repetition             |
| Difficult to maintain | Changes update everywhere |
| No hierarchy          | Real-world modeling       |
| Limited extension     | Easy extension            |

Real-world logic:
A Student **is a** Person.
A Car **is a** Vehicle.
A SavingAccount **is a** BankAccount.

Such relationships justify inheritance.

---

## 3. Basic Structure of Inheritance

General syntax:

```
class Derived : access_mode Base {
    // additional members
};
```

Access mode: `public`, `protected`, `private`.

The derived class contains:

1. All eligible members of the base class (based on inheritance mode)
2. Its own additional data members and functions

Thus, the derived class = base class features + its own added features

---

## 4. Access Mode and Member Visibility

The visibility of inherited members depends on the access mode used during inheritance.
This determines how members of the base class appear *inside* and *outside* the derived class.

| Base Class Member | Under Public Inheritance | Under Protected Inheritance | Under Private Inheritance |
| ----------------- | ------------------------ | --------------------------- | ------------------------- |
| Public            | Public                   | Protected                   | Private                   |
| Protected         | Protected                | Protected                   | Private                   |
| Private           | Not inherited            | Not inherited               | Not inherited             |

Key points to understand:

1. **Private members of a base class are never directly inherited**.
   They remain inaccessible from derived classes.

2. **Public inheritance is the standard form** because it keeps the original meaning:
   Student is a Person → valid is-a relationship

3. **Protected inheritance restricts exposure** — useful when you want derived classes to have access but not the outside world.

4. **Private inheritance is not used for is-a relationships**
   because the derived class hides the base class interface from users. It is used only when the derived class wants to reuse implementation internally.

---

## 5. Constructor and Destructor Behavior under Inheritance

Constructors and destructors do not get inherited.
However, their **execution order depends on inheritance**.

When a derived class object is created:

Constructor call sequence:

1. Base class constructor executes first
2. Derived class constructor executes second

When the object is destroyed:

Destructor call sequence:

1. Derived class destructor executes first
2. Base class destructor executes last

Proof:

```cpp
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A constructor" << endl; }
    ~A() { cout << "A destructor" << endl; }
};

class B : public A {
public:
    B() { cout << "B constructor" << endl; }
    ~B() { cout << "B destructor" << endl; }
};

int main() {
    B obj;
}
```

### **Output**

```
A constructor
B constructor
B destructor
A destructor
```

Sequence is always stable because the base part must exist before and after the derived part.

Reason:
The derived object is built on top of the base; hence the base must exist before the derived object can exist, and must be destroyed last.

---

## 6. Parameterized Constructors and Initialization List

If the base class does not have a default constructor, or if the base constructor requires arguments, the derived class must explicitly call it using an initialization list:

```
Derived(parameters) : Base(arguments) {
    // derived initialization
}
```
```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) {
        name = n;
        age = a;
    }
};

class Student : public Person {
public:
    int roll;

    Student(string n, int a, int r) : Person(n, a) {
        roll = r;
    }

    void info() {
        cout << name << endl;
        cout << age << endl;
        cout << roll << endl;
    }
};

int main() {
    Student s("Rahul Kumar", 21, 1234);
    s.info();
}
```

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
    Student s("Rahul Kumar", 21, 1234);
    s.getInfo();
    return 0;
}
```

### **Output**

```
Rahul Kumar
21
1234
```

Without the initialization list, the program will not compile because `Person(name, age)` must be called before `Student`.

---

## 7. Protected Members and Inheritance

```cpp
class A {
protected:
    int x;
};

class B : public A {
public:
    void set(int v) { x = v; }
    void display() { cout << x << endl; }
};

int main() {
    B obj;
    obj.set(55);
    obj.display();
}
```

### **Output**

```
55
```

Protected members allow:

* Direct use inside the base class
* Direct use inside derived classes

But they remain inaccessible to outside objects.

This provides a controlled sharing mechanism:
visible to subclasses, hidden from external code.

---

## Access Mode and Member Visibility Table

> Private members are never inherited directly.

Demonstration code:

```cpp
class A {
public:
    int pub = 10;
protected:
    int pro = 20;
private:
    int pri = 30;
};

class B : public A {
public:
    void show() {
        cout << pub << endl;  // accessible
        cout << pro << endl;  // accessible
        // cout << pri;       // error: private never inherited
    }
};
```
---

## Protected Members in Inheritance

Protected allows controlled sharing:

```cpp
class A {
protected:
    int x;
};

class B : public A {
public:
    void setX(int value) {
        x = value;   // allowed because x is protected
    }
    void display() {
        cout << x << endl;
    }
};

int main() {
    B obj;
    obj.setX(100);
    obj.display();
}
```

Protected = accessible to base + derived, not to objects.

---

## When Inheritance Should and Should Not Be Used

Correct usage (is-a):

```cpp
class Animal {};
class Dog : public Animal {};   // Dog is an Animal
```

Wrong usage (has-a → composition preferred):

```cpp
class Engine {};
class Car {
private:
    Engine engine;  // Car HAS AN engine, so composition is correct
};
```

> Inheritance is correct only when the relationship is truly **is-a**, not **has-a**.

---

## 8. When Inheritance Should and Should Not Be Used

### It should be used when:

* The relationship is truly **is-a**

  * Student is a Person
  * Car is a Vehicle
  * SavingAccount is a BankAccount

In these cases, the derived class extends or specializes the base class.

Inheritance forces a structural relationship. It must represent classification, not ownership.

### It should NOT be used when:

* The relationship is **has-a** instead of is-a

  * Car has an Engine (composition preferred)
  * Student has a Laptop (composition preferred)

Improper inheritance leads to:

* Tight coupling
* Fragile architecture
* Poor maintainability

---

## 9. Characteristics of Good Inheritance Design

A well-designed inheritance structure satisfies the following:

1. The base class represents general behavior
2. The derived class represents specialized behavior
3. Derived class extends functionality rather than replacing everything
4. Common attributes are centralized in the base class
5. Code is readable and relationships are meaningful

---

## 10. Core Summary Before Types

| Concept                   | Correct Meaning                                  |
| ------------------------- | ------------------------------------------------ |
| Purpose                   | Reuse + Extension                                |
| Derived class consists of | Base class features + New features               |
| Base private members      | Never inherited directly                         |
| Public inheritance        | Models real-world “is-a”                         |
| Constructor order         | Base → Derived                                   |
| Destructor order          | Derived → Base                                   |
| Initialization list       | Required when base has parameterized constructor |

---

## Summary

Before learning the types of inheritance, a clear understanding of the concepts above is required:

* Inheritance is a mechanism of reusing and extending existing classes
* Derived class = Base class features + additional features
* Visibility of inherited members depends on the access mode
* Constructors and destructors have defined execution sequences
* Initialization lists are required to invoke parameterized base constructors
* Inheritance must be used only when an is-a relationship exists, not when has-a exists

---
---

# **TYPES OF INHERITANCE IN C++**

There are **5 types of inheritance** in C++:

| Type                     | Meaning                                      |
| ------------------------ | -------------------------------------------- |
| Single Inheritance       | One base → one derived                       |
| Multilevel Inheritance   | Chain of inheritance (A → B → C)             |
| Multiple Inheritance     | One derived inherits from more than one base |
| Hierarchical Inheritance | One base → many derived                      |
| Hybrid Inheritance       | Combination of two or more types             |

---

## **1. Single Inheritance**

A single derived class inherits from a single base class.

```
Base
  ↓
Derived
```

### **Example**

```cpp
#include <iostream>
using namespace std;

class Person {
public:
    string name;
};

class Student : public Person {
public:
    int roll;
};

int main() {
    Student s;
    s.name = "Rahul";
    s.roll = 101;
    cout << s.name << endl;
    cout << s.roll << endl;
}
```

### **Output**

```
Rahul
101
```

### Where Used

*When there is a simple specialization:*
Student is a Person, Manager is an Employee, Dog is an Animal.

---

## **2. Multilevel Inheritance**

Inheritance occurs in multiple levels — a derived class acts as base for another derived class.

```
Grandparent (A)
      ↓
 Parent (B)
      ↓
Child (C)
```

### **Example**

```cpp
#include <iostream>
using namespace std;

class A {
public:
    int x = 10;
};

class B : public A {
public:
    int y = 20;
};

class C : public B {
public:
    int z = 30;
};

int main() {
    C obj;
    cout << obj.x << endl;
    cout << obj.y << endl;
    cout << obj.z << endl;
}
```

### **Output**

```
10
20
30
```

### Where Used

*Generation chain:*
Human → Employee → Manager
Vehicle → Car → SportsCar

---

## **3. Multiple Inheritance**

A derived class inherits from **more than one base class**.

```
 Base1       Base2
    \         /
      \      /
       Derived
```

### **Example**

```cpp
#include <iostream>
using namespace std;

class A {
public:
    int x = 10;
};

class B {
public:
    int y = 20;
};

class C : public A, public B {
public:
    int z = 30;
};

int main() {
    C obj;
    cout << obj.x << endl;
    cout << obj.y << endl;
    cout << obj.z << endl;
}
```

### **Output**

```
10
20
30
```

### Real-World Example

Teacher + Researcher → Professor
Car + Boat → Amphibious Vehicle

### Important Note

Multiple inheritance can cause ambiguity when both base classes contain members with the same name.
Virtual inheritance resolves that ambiguity (covered later if needed).

---

## **4. Hierarchical Inheritance**

One **base class** has **multiple derived classes**.

```
        Base
      /   |   \
 Derived1 Derived2 Derived3
```

### **Example**

```cpp
#include <iostream>
using namespace std;

class Person {
public:
    string name;
};

class Student : public Person {
public:
    int roll;
};

class Teacher : public Person {
public:
    double salary;
};

int main() {
    Student s;
    s.name = "Riya";
    s.roll = 21;

    Teacher t;
    t.name = "Aman";
    t.salary = 50000.25;

    cout << s.name << " " << s.roll << endl;
    cout << t.name << " " << t.salary << endl;
}
```

### **Output**

```
Riya 21
Aman 50000.25
```

### Where Used

One category → many specialized classes
Vehicle → Car, Bike, Truck
Person → Student, Teacher, Doctor

---

## **5. Hybrid Inheritance**

A combination of two or more types of inheritance.

Most commonly: **Multiple + Multilevel**
(very often creates the “diamond problem,” solved using virtual inheritance)

```
       A
     /   \
    B     C
      \  /
        D
```

### **Basic Example**

```cpp
#include <iostream>
using namespace std;

class A {
public:
    int a = 10;
};

class B : public A {};
class C : public A {};

class D : public B, public C {
public:
    int d = 40;
};

int main() {
    D obj;
    // cout << obj.a;  // ambiguity (two copies of A inherited)
    cout << obj.d << endl;
}
```

### **Output**

```
40
```

If `obj.a` is accessed, ambiguity occurs because D contains two copies of A.
This is handled using **virtual inheritance** (advanced concept).

---

## **Comparison Table**

| Type         | Base Classes | Derived Classes | Common Use Case                     |
| ------------ | ------------ | --------------- | ----------------------------------- |
| Single       | 1            | 1               | Basic extension                     |
| Multilevel   | 1 → 1 → 1    | Chain           | Generational hierarchy              |
| Multiple     | 2+           | 1               | Combining features                  |
| Hierarchical | 1            | 2+              | One common template → many subtypes |
| Hybrid       | Mixed        | Mixed           | Complex inheritance structures      |

---

## Summary

| If you see relationship         | Type         |
| ------------------------------- | ------------ |
| One parent → one child          | Single       |
| One parent → child → grandchild | Multilevel   |
| Two or more parents → one child | Multiple     |
| One parent → many children      | Hierarchical |
| Mixture of the above types      | Hybrid       |

---