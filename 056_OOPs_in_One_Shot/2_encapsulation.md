# Encapsulation (Object-Oriented Programming)

## Definition

Encapsulation is an OOP concept in which **a class bundles data (variables) and the methods (functions) that work on that data in one unit**, and **prevents direct access to the internal data from outside the class**.
Access to data is controlled using **access modifiers (private, public, protected)** and **getter/setter functions**.

---

## Why Encapsulation is Important

1. **Protects data from accidental or unauthorized modification**
2. **Allows controlled interaction with data using methods instead of direct access**
3. **Hides internal logic and exposes only necessary features (Abstraction + Encapsulation)**
4. **Makes code more secure, reliable, and easier to maintain**
5. **Allows validation before updating data (through setters)**

---

## Real-World Simple Example (Conceptual)

A bank ATM lets users withdraw money but does not allow them direct access to the bank’s internal data.
They request money → system checks balance → approves or rejects → updates balance safely.

Same idea in programming: data is protected inside a class and can only be modified through controlled functions.

---

### Key Idea in One Line

Encapsulation means **“don’t touch data directly — access it only through allowed methods.”**

---

## How Encapsulation Works

| Step | Meaning                                                                                   |
| ---- | ----------------------------------------------------------------------------------------- |
| 1    | Declare variables as **private** (hidden)                                                 |
| 2    | Provide **public methods** (getters/setters or other functions) to read/write data safely |

---

## Visual Understanding

```
Class → contains data + methods
      ↓
Private data → not accessible directly
Public methods → control access to private data
```

---

## Example Code (C++)

```cpp
class Employee {
private:
    double salary;  // hidden data

public:
    void setSalary(double s) {   // setter
        if (s > 0)
            salary = s;
    }
    double getSalary() {         // getter
        return salary;
    }
};
```

---

## Why direct access should not be allowed

Without encapsulation:

```cpp
emp.salary = -50000;   // invalid and unsafe
```

With encapsulation, such invalid updates are prevented because data is protected inside the class.

---

## Advantages

1. **Security** – sensitive data stays protected
2. **Data validation** – setters can reject invalid values
3. **Reduced complexity** – outside code only uses public methods
4. **Flexibility** – internal implementation can be changed later without affecting other code
5. **Improved maintainability** – low coupling

---

## Encapsulation vs Abstraction

| Encapsulation                                    | Abstraction                                      |
| ------------------------------------------------ | ------------------------------------------------ |
| Hides data                                       | Hides implementation details                     |
| Achieved with private variables + public methods | Achieved with abstract classes, interfaces, etc. |
| Focus on protection                              | Focus on simplification                          |

Encapsulation helps achieve abstraction but both are not the same.

---

## Key Terms

| Term        | Meaning                           |
| ----------- | --------------------------------- |
| **Private** | Accessible only inside the class  |
| **Public**  | Accessible from outside the class |
| **Getter**  | Method to read private data       |
| **Setter**  | Method to modify private data     |

---

## Memory & Execution Angle

* Private data is stored in object memory
* Public methods act like a **gatekeeper** to that memory
* Only authorized functions can update or read the data

---

## Important Interview Points

* Encapsulation ensures **data hiding, security, and controlled access**
* “Private data + public methods” = correct textbook formula
* It decouples code and increases maintainability
* Useful in real-world modules like **bank accounts, login systems, medical records, payment apps, APIs**

---

## One-Shot Revision

* Hide data using `private`
* Access it using `public` getters and setters
* Prevents unauthorized and invalid modification
* Helps achieve abstraction and increases security

---

## Comparison of **public**, **protected**, and **private**

| Access Specifier | Accessible Inside Class | Accessible in Derived Class | Accessible Outside Class | Typical Use                                                                   |
| ---------------- | ----------------------- | --------------------------- | ------------------------ | ----------------------------------------------------------------------------- |
| public           | Yes                     | Yes                         | Yes                      | Functions and variables that should be freely accessible outside the class    |
| protected        | Yes                     | Yes                         | No                       | Members that should be inherited but must not be accessed directly by objects |
| private          | Yes                     | No                          | No                       | Data that must be hidden and accessed only through methods                    |

Quick memory tip:
**public → everywhere**
**protected → class + derived classes**
**private → only inside class**

---

## Easy complete code that shows all three (public, protected, private)

```cpp
#include <iostream>
using namespace std;

class Person {
private:
    int age;                    // private → only inside Person

protected:
    string address;             // protected → inside Person + derived class

public:
    string name;                // public → anywhere

    void setAge(int a) {        // setter to update private data safely
        if (a > 0)
            age = a;
    }
    int getAge() {              // getter to read private data
        return age;
    }
};

class Student : public Person {
public:
    void setAddress(string ad) {
        address = ad;           // allowed because address is protected
    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << getAge() << endl;
    }
};

int main() {
    Student s;
    s.name = "Aditi";           // public access allowed
    s.setAddress("Chandigarh");
    s.setAge(21);               // age cannot be accessed directly because it's private

    s.show();
    return 0;
}
```
Output:  
```
Name: Aditi
Address: Chandigarh
Age: 21
```

### What this code demonstrates

| Member  | Where accessed                      | Explanation             |
| ------- | ----------------------------------- | ----------------------- |
| name    | direct access in main               | because it is public    |
| address | accessed inside derived class only  | because it is protected |
| age     | accessed only through setAge/getAge | because it is private   |