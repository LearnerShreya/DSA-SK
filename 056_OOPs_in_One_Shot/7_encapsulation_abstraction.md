
## **Encapsulation vs Abstraction (Difference)**

| Feature               | Encapsulation                                                                                | Abstraction                                                                    |
| --------------------- | -------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| **Meaning**           | Wrapping data and methods into a single unit (class) and protecting them from outside access | Showing only the essential features and hiding internal implementation details |
| **Purpose**           | To safeguard data and restrict unauthorized access                                           | To reduce complexity and focus only on important functionality                 |
| **Focus**             | *How data is stored & accessed*                                                              | *What the object does* rather than how                                         |
| **Achieved using**    | Classes, objects, access specifiers (private, protected, public)                             | Abstract classes, interfaces, pure virtual functions                           |
| **Hides**             | Data                                                                                         | Implementation                                                                 |
| **Main Benefit**      | Security and control over data                                                               | Simplicity and design clarity                                                  |
| **Example in code**   | Private variables with getters/setters                                                       | Pure virtual function forcing derived class to provide implementation          |
| **Real life example** | ATM protects your PIN from direct access                                                     | ATM lets you withdraw money without knowing internal workings                  |

---

## **Quick Intuition**

| Concept           | Intuition                                            |
| ----------------- | ---------------------------------------------------- |
| **Encapsulation** | “Don’t touch data directly — use methods.”           |
| **Abstraction**   | “You don’t need to know how it works — just use it.” |

---

## **Short Examples**

### **Encapsulation Example**

```cpp
class Student {
private:
    string name;   // hidden data
public:
    void setName(string n) { name = n; } // controlled access
    string getName() { return name; }
};
```

→ Data is protected, accessed only through member functions.

### **Abstraction Example**

```cpp
class Animal {
public:
    virtual void sound() = 0; // pure virtual function
};
class Dog : public Animal {
public:
    void sound() { cout << "Bark"; }
};
```

→ We only know every animal has sound(), but implementation is hidden.

---

## **One-Line Summary**

* **Encapsulation = data protection**
* **Abstraction = complexity reduction**

Both are OOP pillars and often work together, but they solve **different problems**.