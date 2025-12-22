# **ABSTRACTION IN C++**

## **1. Concept**

Abstraction means **showing only the essential features of an object and hiding its unnecessary internal details**.

Simple explanation:

> We interact with the result, not the internal complexity.

Example in real life:

* You use a **smartphone** without knowing how the processor works.
* You drive a **car** without knowing how the engine burns fuel.

Same happens in programming:
The user of a class does **not need to know how the logic is implemented**, only **what the function does**.

---

## **2. Purpose of Abstraction**

| Benefit         | Explanation                                                            |
| --------------- | ---------------------------------------------------------------------- |
| Simplicity      | User focuses only on what to use, not how it is implemented            |
| Security        | Internal data and logic can be protected from external misuse          |
| Maintainability | Internal changes do not affect external code if interface remains same |
| Avoid confusion | Complex implementation is hidden behind simple functions               |

---

## **3. How Abstraction is implemented in C++**

There are **two main ways**:

### **A) Using Classes**

Public interface is visible to the user; private details are hidden.

```cpp
class CoffeeMachine {
private:
    void grindBeans() {}
    void brew() {}
public:
    void makeCoffee() {
        grindBeans();
        brew();
        cout << "Coffee ready\n";
    }
};
```

User calls only:

```cpp
CoffeeMachine c;
c.makeCoffee();   // Does not know internal process
```

### **B) Using Abstract Classes + Pure Virtual Functions**

Abstract class provides a **general idea**, while derived classes provide **real implementation**.

```cpp
class Shape {
public:
    virtual void draw() = 0; // pure virtual → function with no body
};
```

Derived class implements it (abstraction + polymorphism):

```cpp
class Circle : public Shape {
public:
    void draw() {
        cout << "Circle drawn\n";
    }
};
```

---

## **4. Pure Virtual Function**

A function declared in base class but **must be overridden** in derived class.

Syntax:

```cpp
virtual return_type function_name() = 0;
```

Class containing at least one pure virtual function becomes an **abstract class**.

---

## **5. Features of Abstract Class**

| Property                  | Meaning      |
| ------------------------- | ------------ |
| Cannot create object      | `Shape s;` ❌ |
| Can have constructor      | ✔ allowed    |
| Can have normal functions | ✔            |
| Can have data members     | ✔            |
| Used as a base class only | ✔            |

Example with pointer:

```cpp
Shape* s;
Circle c;
s = &c;
s->draw();       // Runtime polymorphism
```

---

## **6. Why Abstraction is Needed**

| Without Abstraction | With Abstraction   |
| ------------------- | ------------------ |
| Exposes complexity  | Hides complexity   |
| Security risk       | Safe internal data |
| Hard maintenance    | Easy maintenance   |
| High coupling       | Low coupling       |

---

## **7. Abstraction vs Encapsulation**

| Feature        | Abstraction                                       | Encapsulation                                    |
| -------------- | ------------------------------------------------- | ------------------------------------------------ |
| Purpose        | Show only necessary functionality                 | Bundle data + methods together                   |
| Focus          | Hiding implementation details                     | Data protection and grouping                     |
| Implementation | Classes, abstract classes, pure virtual functions | Access specifiers (private / public / protected) |
| Example        | Using `draw()` without knowing code               | Private variables with public setters/getters    |

Both work together:

* Encapsulation hides **data**
* Abstraction hides **logic**

---

## **8. Common Interview Questions**

| Question                                | Short Answer                                                           |
| --------------------------------------- | ---------------------------------------------------------------------- |
| What is abstraction?                    | Hiding internal implementation and showing only required functionality |
| How is abstraction achieved in C++?     | Through classes and pure virtual functions (abstract classes)          |
| Can we create object of abstract class? | No                                                                     |
| Why use pure virtual functions?         | To force derived classes to implement the function                     |
| Can abstract class have normal methods? | Yes                                                                    |

---

## **9. Final Key Takeaways**

* Abstraction reduces complexity and increases security.
* Abstract classes **do not allow objects** and act as **templates** for derived classes.
* Pure virtual function ensures **mandatory overriding**.
* Real power of abstraction appears with **late binding / runtime polymorphism**.

---

```cpp
#include <iostream>
#include <string>
using namespace std;

class Shape {   // abstract class
public:
    virtual void draw() = 0;   // pure virtual function
};

class Circle : public Shape {
public:
    void draw() {
        cout << "drawing a circle\n";
    }
};

int main() {
    // Shape s;          // ❌ Not allowed (cannot create object of abstract class)
    Circle c1;           // ✔ allowed
    c1.draw();           // calls overridden draw()
    return 0;
}
```

### Output

```
drawing a circle
```

### Key points

| Concept               | Meaning                                                                          |
| --------------------- | -------------------------------------------------------------------------------- |
| Abstract class        | A class having at least one pure virtual function                                |
| Pure virtual function | Function with `= 0`, forces overriding in derived class                          |
| Object creation       | Abstract class objects **cannot** be created                                     |
| Use case              | To enforce the rule that every derived class must provide its own implementation |

---

## **ABSTRACT CLASS**

### **1. Concept**

An **abstract class** provides a **generic idea / blueprint / interface** that other classes must follow.
It exists only to be inherited — **not to create objects**.

A class becomes *abstract* when it contains **at least one pure virtual function**.

```cpp
virtual void functionName() = 0;
```

---

### **2. Why Abstract Class Exists**

| Purpose              | Explanation                                                        |
| -------------------- | ------------------------------------------------------------------ |
| Blueprint            | Creates a common standard for derived classes                      |
| Force rules          | Makes sure derived classes implement certain functions             |
| Runtime polymorphism | Enables late binding using base class pointers                     |
| Code consistency     | Same function name across subclasses but different implementations |

---

### **3. Real-World Analogy**

Think of an **ATM card interface**:

* It forces every bank (SBI / HDFC / ICICI) to implement `withdraw()` and `transfer()`
* But the internal logic of each bank is different

Same in programming:

* Base abstract class defines **what must exist**
* Child classes define **how it works**

---

### **4. Essential Properties**

| Feature                | Status                  |
| ---------------------- | ----------------------- |
| Object creation        | ❌ Not allowed           |
| Constructor            | ✔ Allowed               |
| Destructor             | ✔ Allowed               |
| Data members           | ✔ Allowed               |
| Normal methods         | ✔ Allowed               |
| Pure virtual functions | ✔ At least one required |
| Multiple inheritance   | ✔ Supported             |
| Friend function        | ✔ Allowed               |

---

### **5. Example**

```cpp
#include <iostream>
using namespace std;

class Shape {     // abstract class
public:
    virtual void draw() = 0;   // pure virtual function
    void info() { cout << "This is a shape\n"; }
};

class Circle : public Shape {
public:
    void draw() { cout << "Drawing Circle\n"; }
};

class Rectangle : public Shape {
public:
    void draw() { cout << "Drawing Rectangle\n"; }
};

int main() {
    Shape* s;           // pointer of abstract class allowed
    Circle c;
    Rectangle r;

    s = &c;  s->draw();    // Circle implementation
    s = &r;  s->draw();    // Rectangle implementation
}
```

### **Output**

```
Drawing Circle
Drawing Rectangle
```

---

### **6. Why Pure Virtual Function**

To ensure that **every derived class must override it**.
If a class does not override a pure virtual function → It also becomes abstract.

---

### **7. Abstract Class vs Concrete Class**

| Type           | Object Creation | Function Implementation |
| -------------- | --------------- | ----------------------- |
| Abstract class | ❌ Not allowed   | Partial implementation  |
| Concrete class | ✔ Allowed       | Full implementation     |

---

### **8. Abstract Class vs Interface in C++**

| Feature                   | Abstract Class                     | Interface (class with only pure virtual functions) |
| ------------------------- | ---------------------------------- | -------------------------------------------------- |
| Contains variables        | ✔ Yes                              | ✔ Yes                                              |
| Contains normal functions | ✔ Yes                              | ❌ Only pure virtual                                |
| Constructor               | ✔ Yes                              | ❌ No practical use                                 |
| Purpose                   | Blueprint + partial implementation | Only blueprint                                     |
| Use case                  | When some logic must be shared     | When no logic is shared                            |

---

### **9. When to Use**

Use an abstract class when:
✔ Parent has **common data or functions**
✔ Derived classes **share logic** but **implement differently**

Avoid it when:
✖ Parent has **zero common logic** → use **Interface style (only pure virtual)**

---

### **10. Key Takeaways**

* Abstract class = **blueprint + partial implementation**
* Pure virtual function = **compulsory overriding**
* Enables **runtime polymorphism**
* Cannot create objects, but **pointers/reference are allowed**

---
---