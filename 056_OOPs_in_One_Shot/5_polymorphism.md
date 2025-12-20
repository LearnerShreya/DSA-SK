# **POLYMORPHISM IN C++**

## **1. Meaning**

Polymorphism means **one name, multiple behaviors**.
A function or operator behaves differently **depending on objects or parameters**.

It is one of the four pillars of OOP:

1. Encapsulation
2. Inheritance
3. Polymorphism
4. Abstraction

---

## **2. Why Polymorphism is needed**

| Reason                           | Benefit                     |
| -------------------------------- | --------------------------- |
| Reuse function names             | Cleaner and readable code   |
| Behavior changes based on object | Flexibility and scalability |
| Supports abstraction             | Real OOP design             |

---

## **3. Types of Polymorphism**

| Type                      | Binding         | Timing       | Examples                                   |
| ------------------------- | --------------- | ------------ | ------------------------------------------ |
| Compile-time Polymorphism | Static Binding  | Compile Time | Function Overloading, Operator Overloading |
| Run-time Polymorphism     | Dynamic Binding | Runtime      | Function Overriding using Virtual Function |

---

---

## **4. COMPILE-TIME POLYMORPHISM**

### **4.1 Function Overloading**

Same function name, but different parameters.

```cpp
void fun(int);
void fun(double);
void fun(string);
```

## **🔹 (1) Function Overloading — Compile-time Polymorphism**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Print {
public:
    void show(int x) {
        cout << "int: " << x << endl;
    }
    void show(double x) {
        cout << "double: " << x << endl;
    }
    void show(string s) {
        cout << "string: " << s << endl;
    }
};

int main() {
    Print p;
    p.show(10);
    p.show(3.14);
    p.show("Hello");
    return 0;
}
```

Rules:

* Parameters must differ in number/type/order
* Return type alone is **not enough** to overload
* Constructors can also be overloaded

---

### **4.2 Operator Overloading**

User-defined meaning for operators.

Example:

```cpp
obj3 = obj1 + obj2;
```

Not every operator can be overloaded (e.g., `?:`, `.` cannot be overloaded).

## **🔹 (2) Operator Overloading — Compile-time Polymorphism**

```cpp
#include <iostream>
using namespace std;

class Add {
public:
    int val;
    Add(int v = 0) {
        val = v;
    }

    Add operator + (Add obj) {
        return Add(val + obj.val);
    }
};

int main() {
    Add a1(4), a2(9);
    Add a3 = a1 + a2;
    cout << "Sum: " << a3.val << endl;
    return 0;
}
```

---

---

## **5. RUN-TIME POLYMORPHISM**

Achieved using **function overriding + virtual keyword**.

### **5.1 Function Overriding**

A derived class rewrites a parent function with:

* Same name
* Same parameters
* Same return type

Overriding can happen **without virtual keyword**, but then it does **not** produce runtime polymorphism.

---

### **5.2 Virtual Function**

Enables **dynamic binding**.
When a virtual function is called through a base pointer, the function of the **object at runtime** is executed.

```cpp
Parent* p = new Child();
p->show();  // Child version runs because show() is virtual
```

Without `virtual`, the **Parent** version executes.


## **🔹 (3) Function Overriding — Without virtual**

```cpp
#include <iostream>
using namespace std;

class Parent {
public:
    void info() {
        cout << "Parent info" << endl;
    }
};

class Child : public Parent {
public:
    void info() {
        cout << "Child info" << endl;
    }
};

int main() {
    Parent p;
    Child c;

    p.info();      // Parent
    c.info();      // Child

    Parent *ptr = &c;
    ptr->info();   // Parent (runtime polymorphism does NOT occur)
    return 0;
}
```

---

## **🔹 (4) Runtime Polymorphism — Using `virtual`**

```cpp
#include <iostream>
using namespace std;

class Parent {
public:
    virtual void show() {
        cout << "Parent show" << endl;
    }
};

class Child : public Parent {
public:
    void show() override {
        cout << "Child show" << endl;
    }
};

int main() {
    Parent *ptr = new Child();
    ptr->show();  // Child (runtime polymorphism)
    delete ptr;
    return 0;
}
```

---

### **5.3 override keyword**

Not mandatory, but recommended.
It ensures the child function truly overrides parent’s function and avoids accidental mistakes.

---

### **5.4 vptr and vtable — simple explanation**

When a class has one or more virtual functions:

* Compiler creates a **vtable** (table storing addresses of virtual functions)
* Each object stores a **vptr** pointer to reference this table
* At runtime, vtable decides which version of function is executed

This is the reason dynamic polymorphism works.

---

### **5.5 Pure Virtual Function & Abstract Class**

Pure virtual function:

```cpp
virtual void draw() = 0;
```

Class with at least one pure virtual function becomes **abstract**.
Abstract class **cannot be instantiated** and only provides a blueprint.


## **🔹 (5) Abstract Class + Pure Virtual Function**

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing circle" << endl;
    }
};

int main() {
    Shape *s = new Circle();
    s->draw();
    delete s;
    return 0;
}
```

---

---

## **6. Overloading vs Overriding vs Virtual Function**

| Feature           | Overloading               | Overriding            | Virtual Function                   |
| ----------------- | ------------------------- | --------------------- | ---------------------------------- |
| Category          | Compile-time polymorphism | Run-time polymorphism | Mechanism for runtime polymorphism |
| Function name     | Same                      | Same                  | Same                               |
| Parameters        | Different                 | Same                  | Same                               |
| Return type       | Can be different          | Must be same          | Must be same                       |
| Keyword needed    | none                      | none                  | virtual                            |
| Binding           | Compile time              | Runtime               | Runtime                            |
| Execution control | Compiler                  | Object type           | Object type + virtual function     |

---

---

## **7. Common Interview Questions (concept summary)**

| Question                                                | Correct understanding                                                                              |
| ------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| Does overriding need virtual?                           | No, overriding can happen without virtual.                                                         |
| Does runtime polymorphism need virtual?                 | Yes.                                                                                               |
| Can constructors be virtual?                            | No.                                                                                                |
| Should destructor be virtual in polymorphic base class? | Yes, to avoid memory leak.                                                                         |
| Is abstract class same as interface?                    | C++ does not have interface; abstract class acts like interface when all methods are pure virtual. |

---

---

## **8. Frequent mistakes**

| Mistake                                                                    | What happens                                          |
| -------------------------------------------------------------------------- | ----------------------------------------------------- |
| Forgetting virtual                                                         | Parent version executes via base pointer              |
| Changing return type in override                                           | Compiler treats it as separate function → no override |
| Calling virtual function inside constructor                                | Base version runs (vptr not set yet)                  |
| Using base class pointer to delete child object without virtual destructor | Memory leak                                           |

---

---

## **9. Short memory map**

| Keyword  | Purpose                        |
| -------- | ------------------------------ |
| virtual  | Enables runtime polymorphism   |
| override | Validates overriding signature |
| = 0      | Pure virtual (abstract class)  |

---

## **10. Five-line revision**

* Polymorphism allows one name to behave differently.
* Overloading and operator overloading give compile-time polymorphism.
* Overriding gives runtime polymorphism **only when using virtual**.
* Virtual functions use vtable and vptr for dynamic binding.
* Pure virtual functions create abstract classes and enforce overriding.

---

### What each code demonstrates

| Program              | Type of Polymorphism                      |
| -------------------- | ----------------------------------------- |
| Function Overloading | Compile-time                              |
| Operator Overloading | Compile-time                              |
| Function Overriding  | Overriding only (NO runtime polymorphism) |
| Virtual Function     | Runtime Polymorphism                      |
| Abstract Class       | Force overriding at runtime               |

---