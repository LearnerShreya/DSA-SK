# OOPs in One Shot

---

# **PART 1 — INTRODUCTION TO OOPS + BASIC BUILDING BLOCKS**

## **1. INTRODUCTION TO OOPS**

### **What is OOP (Object-Oriented Programming)?**

OOP is a way of writing programs where we organize everything around **objects**, and each object contains:

* **Data** (variables)
* **Behaviour** (functions)

The goal is to make code:

* easier to understand
* reusable
* secure
* maintainable
* closer to real-world concepts

### **Why OOP?**

Some key benefits:

* reduces duplicate code
* easy to update
* helps in teamwork
* gives better security
* helps build large software easily

Real-life example:
A **car** is an object. It has:

* data: color, model, speed
* behaviour: start(), brake(), accelerate()

That’s exactly what OOP does.

---

## **2. CLASS & OBJECT**

### **Class — Definition**

A class is a **blueprint** or a **template**.
It defines the structure of data and functions.

### **Object — Definition**

An object is a **real instance** created from a class.

Example:

* Class: *Human*
* Objects: Shreya, Priya, Rahul

### **C++ Example**

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int speed;

    void start() {
        cout << "Car started" << endl;
    }
};

int main() {
    Car obj;      // object creation
    obj.brand = "BMW";
    obj.speed = 120;

    cout << obj.brand << " " << obj.speed << endl;
    obj.start();
}
```

---

## **3. ACCESS SPECIFIERS**

Access specifiers decide **who can access members of the class**.

### **Types**

1. **public** – accessible anywhere
2. **private** – accessible only inside class
3. **protected** – accessible inside class + child class

### **Example**

```cpp
class Student {
private:
    int roll;

public:
    void setRoll(int r) {
        roll = r;
    }

    int getRoll() {
        return roll;
    }
};
```

Here, **roll** is safe because it’s private.

---

## **4. ENCAPSULATION**

### **Definition**

Encapsulation means **wrapping data and functions together** inside a class and **protecting data** using access specifiers.

Goal of encapsulation:

* hide data
* control access
* increase security

### **Example**

```cpp
class Bank {
private:
    int balance;

public:
    void setBalance(int b) {
        balance = b;
    }

    int getBalance() {
        return balance;
    }
};
```

This protects `balance`.

---

## **5. CONSTRUCTOR**

### **Definition**

A constructor is a special function that:

* has the same name as class
* runs automatically when object is created
* initializes data

### **Types of Constructors**

1. Default constructor
2. Parameterized constructor
3. Copy constructor (next section)

---

### **Example**

```cpp
class Person {
public:
    string name;
    int age;

    Person() {        // default
        name = "Unknown";
        age = 0;
    }

    Person(string n, int a) {   // parameterized
        name = n;
        age = a;
    }
};
```

---

## **6. THIS POINTER**

### **Definition**

`this` is a pointer that stores the **address of the current object**.

Used when:

* parameter name = member name
* to return current object

### **Example**

```cpp
class Demo {
private:
    int x;

public:
    void setX(int x) {
        this->x = x; // differentiate between both x
    }
};
```

---

## **7. COPY CONSTRUCTOR**

### **Definition**

A constructor that creates a **new object** using an **existing object**.

### **Syntax**

```cpp
ClassName (const ClassName &obj) {
}
```

### **Example**

```cpp
class A {
public:
    int value;

    A(int v) {
        value = v;
    }

    A(const A &obj) {   // copy constructor
        value = obj.value;
    }
};
```

---

## **8. SHALLOW COPY vs DEEP COPY**

### **Shallow Copy**

* copies memory address
* two objects share the **same memory**
* dangerous for pointers

### **Deep Copy**

* copies actual value
* allocates new memory
* safe and recommended

### **Example**

```cpp
class Demo {
public:
    int *ptr;

    Demo(int val) {
        ptr = new int(val);
    }

    Demo(const Demo &d) {     // deep copy
        ptr = new int(*d.ptr);
    }
};
```

---

## **9. DESTRUCTOR**

### **Definition**

Destructor is a special function that:

* has same name as class
* starts with `~`
* runs automatically when object dies
* frees memory

### **Example**

```cpp
class Test {
public:
    Test() {
        cout << "Object created" << endl;
    }

    ~Test() {
        cout << "Object destroyed" << endl;
    }
};
```

---

## **10. INHERITANCE (BASE OF OOP)**

### **Definition**

Inheritance allows one class (child) to acquire the properties of another class (parent).

### **Why Inheritance?**

* code reusability
* extension of existing classes
* hierarchical structure

### **Example**

```cpp
class Animal {
public:
    void eat() {
        cout << "Eating" << endl;
    }
};

class Dog : public Animal {     // Dog inherits Animal
public:
    void bark() {
        cout << "Barking" << endl;
    }
};
```

---

## **11. MODES OF INHERITANCE**

These control access of inherited members.

1. **public inheritance**

   * public → public
   * protected → protected
   * private → not accessible

2. **protected inheritance**

   * public → protected
   * protected → protected

3. **private inheritance**

   * public → private
   * protected → private

---

---

# **PART 2 — ADVANCED OOPS CONCEPTS**

# **12. TYPES OF INHERITANCE**

Inheritance can be of several types based on how classes are connected.

### **1. Single Inheritance**

One child inherits from one parent.

```cpp
class A {
public:
    void showA() { cout << "A" << endl; }
};

class B : public A {
public:
    void showB() { cout << "B" << endl; }
};
```

---

### **2. Multilevel Inheritance**

Parent → Child → Grandchild

```cpp
class A { };
class B : public A { };
class C : public B { };
```

---

### **3. Multiple Inheritance**

Child inherits from **multiple parents**.

```cpp
class A {};
class B {};
class C : public A, public B {};
```

---

### **4. Hierarchical Inheritance**

One parent → many children.

```cpp
class A {};
class B : public A {};
class C : public A {};
```

---

### **5. Hybrid Inheritance**

Combination of multiple types.

(Like diamond problem)

---

# **13. POLYMORPHISM**

### **Definition**

Polymorphism means **same name, different behavior**.

Two types:

1. **Compile-time Polymorphism**
2. **Run-time Polymorphism**

---

# **14. FUNCTION OVERLOADING (Compile-time Polymorphism)**

### **Definition**

Same function name, different parameters.

### **Rules**

* change number of arguments
* or change type of arguments
* return type alone can't overload

### **Example**

```cpp
class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};
```

---

# **15. FUNCTION OVERRIDING (Run-time Polymorphism)**

### **Definition**

A child class gives **its own implementation** of a parent class function.

### **Conditions**

* same function name
* same parameters
* inheritance required

### **Example**

```cpp
class Parent {
public:
    void show() {
        cout << "Parent show" << endl;
    }
};

class Child : public Parent {
public:
    void show() {
        cout << "Child show" << endl;
    }
};
```

---

# **16. VIRTUAL FUNCTION (Key for run-time polymorphism)**

### **Definition**

A virtual function ensures **function overriding works based on object type**, not pointer type.

### **Why virtual?**

Without virtual:

* parent pointer → parent function
  With virtual:
* parent pointer → child function

### **Example**

```cpp
class Base {
public:
    virtual void show() {
        cout << "Base show" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived show" << endl;
    }
};

int main() {
    Base* ptr;
    Derived d;
    ptr = &d;
    ptr->show();   
}
```

Output:

```
Derived show
```

---

# **17. ABSTRACTION**

### **Definition**

Abstraction means showing only **necessary details** and hiding unnecessary internal working.

Real-life example:
You use a phone → you don't care about internal circuits.

### **How to achieve abstraction in C++?**

* abstract classes
* interfaces (using pure virtual functions)

---

# **18. ABSTRACT CLASS**

### **Definition**

A class that **cannot be instantiated** and contains at least one **pure virtual function**.

### **Syntax**

```cpp
virtual void func() = 0;
```

### **Example**

```cpp
class Shape {
public:
    virtual void draw() = 0;      // pure virtual
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing circle" << endl;
    }
};
```

---

# **19. STATIC KEYWORD**

The `static` keyword has different meanings depending on usage.

### **1. Static Data Member**

* shared by all objects
* only 1 copy exists

```cpp
class Student {
public:
    static int count;

    Student() {
        count++;
    }
};

int Student::count = 0;
```

---

### **2. Static Member Function**

* can access only static members
* called without object

```cpp
class A {
public:
    static void msg() {
        cout << "Static function" << endl;
    }
};

int main() {
    A::msg();   
}
```

---

### **3. Static Variable (inside function)**

* retains value between function calls

```cpp
void fun() {
    static int x = 0;
    x++;
    cout << x;
}
```

---

---

# **PART 3 — OOPS SUMMARY + COMPARISONS + INTERVIEW Q&A**

# **1. QUICK REVISION NOTES (SUPER SHORT + CLEAR)**

### **Class**

A template containing data + functions.

### **Object**

A real instance created from a class.

### **Encapsulation**

Binding data and functions together; hiding data using private.

### **Constructor**

Automatically initializes object when created.

### **Destructor**

Automatically destroys object when it goes out of scope.

### **this Pointer**

Points to the current object.

### **Copy Constructor**

Creates new object from an existing object.

### **Shallow Copy**

Copies pointer, not data (shares same memory).

### **Deep Copy**

Allocates new memory and copies actual value.

### **Inheritance**

Acquiring properties of parent class into child class.

### **Polymorphism**

Same name, different behaviour.

### **Function Overloading**

Same name, different parameters (compile-time).

### **Function Overriding**

Same name, same parameters in child (run-time).

### **Virtual Function**

Ensures child function is called via parent pointer.

### **Abstraction**

Showing essential info, hiding internal complexity.

### **Abstract Class**

A class with pure virtual function(s).

### **Static Keyword**

Shared members, function without object, persistent variable.

---

# **2. CLEAN COMPARISON TABLES**

## **A. Overloading vs Overriding**

| Feature        | Overloading        | Overriding              |
| -------------- | ------------------ | ----------------------- |
| Type           | Compile-time       | Run-time                |
| Parameters     | Must differ        | Same                    |
| Class Relation | Same class         | Inheritance required    |
| Purpose        | Increase usability | Change parent behaviour |

---

## **B. Shallow Copy vs Deep Copy**

| Feature  | Shallow            | Deep                       |
| -------- | ------------------ | -------------------------- |
| Memory   | Same memory shared | Separate memory allocated  |
| Safety   | Risky              | Safe                       |
| Speed    | Faster             | Slower                     |
| Use-case | Simple objects     | Pointer-containing objects |

---

## **C. Constructor vs Destructor**

| Feature | Constructor               | Destructor                |
| ------- | ------------------------- | ------------------------- |
| Purpose | Initialize object         | Cleanup memory            |
| Name    | Class name                | ~Class name               |
| Calls   | Automatically on creation | Automatically on deletion |
| Count   | Can have many             | Only one                  |

---

## **D. Compile-time vs Run-time Polymorphism**

| Type             | Compile-time | Run-time             |
| ---------------- | ------------ | -------------------- |
| Achieved using   | Overloading  | Overriding + virtual |
| Decision made by | Compiler     | Runtime              |
| Speed            | Faster       | Slightly slower      |

---

# **3. INTERVIEW QUESTION BANK (WITH SHORT ANSWERS)**

### **Q1. What is OOP and why is it used?**

A method of programming using objects. Used for reusability, security, easy maintenance.

---

### **Q2. What is a class and object?**

Class is a blueprint, object is its instance.

---

### **Q3. Why do we need a constructor?**

To initialize data automatically when object is created.

---

### **Q4. Can a constructor be private? Why?**

Yes. Used in singleton pattern.

---

### **Q5. Difference between this pointer and pointer to object?**

this refers to current object; pointer to object refers to external object.

---

### **Q6. What is a virtual function?**

A function created for run-time polymorphism.

---

### **Q7. What is abstraction?**

Showing essential info and hiding internal working.

---

### **Q8. Can we create object of abstract class?**

No.

---

### **Q9. Why use static members?**

To share data among all objects.

---

### **Q10. What is the diamond problem?**

Multiple inheritance creating ambiguity.
Solved using **virtual inheritance**.

---

# **4. SIMPLE REAL-WORLD EXAMPLES FOR BETTER MEMORY**

### **Encapsulation Example**

A medicine capsule hides powder inside — users cannot see internal content.

### **Abstraction Example**

You use a washing machine without knowing motor implementation.

### **Inheritance Example**

Instagram stories → Snapchat stories
Instagram inherited the idea and extended it.

### **Polymorphism Example**

Your Aadhaar card:
You can use it at bank, airport, SIM card place — same card, multiple behaviours.

---

# **5. SMALL C++ PRACTICAL PROGRAM USING ALL OOPS FEATURES**

This combines everything — classes, constructor, inheritance, overriding, virtual, static, encapsulation.

```cpp
#include <iostream>
using namespace std;

class Person {
private:
    int age;

public:
    static int count;

    Person(int age) {
        this->age = age;
        count++;
    }

    virtual void work() {
        cout << "Person works" << endl;
    }

    int getAge() {
        return age;
    }

    virtual ~Person() {
        cout << "Person destroyed" << endl;
    }
};

int Person::count = 0;

class Employee : public Person {
private:
    string job;

public:
    Employee(int age, string job) : Person(age) {
        this->job = job;
    }

    void work() {
        cout << "Employee working as " << job << endl;
    }
};

int main() {
    Person* p = new Employee(22, "Developer");

    cout << "Age: " << p->getAge() << endl;
    p->work();

    cout << "Total persons: " << Person::count << endl;

    delete p;
}
```

---

# **6. END SUMMARY (SUPER SHORT FOR REVISION)**

OOP = class + object + encapsulation + abstraction + inheritance + polymorphism.

Pillars:

1. Encapsulation
2. Inheritance
3. Polymorphism
4. Abstraction

Extra concepts:
Constructor, destructor, this pointer, static, copy constructor, deep copy, virtual functions, access specifiers.

---