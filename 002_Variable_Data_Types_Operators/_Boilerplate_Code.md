

# 📓 Boilerplate Code

---

## 🔹 What is Boilerplate Code?

**Boilerplate code** is the **basic skeleton or standard structure** of a program that must be written every time you start coding in a particular language.

It usually includes:

* Program starting point
* Function/method definitions
* Necessary imports/includes

Even if your program does nothing yet, boilerplate code ensures it's **valid and ready to run**.

---

## 🔸 C++ Boilerplate Code (No Output)

```cpp
#include <iostream>     // Header for I/O operations
using namespace std;    // Avoids prefixing std:: (optional)

int main() {            // Entry point of the program
    
    // Your logic goes here

    return 0;           // Indicates successful program execution
}
```

### ✅ Alternate Version (Without `using namespace std`)

```cpp
#include <iostream>

int main() {
    
    // Your logic goes here

    return 0;
}
```

---

### 🔍 Notes Explanation – C++

| Line                   | Purpose                                      |
| ---------------------- | -------------------------------------------- |
| `#include <iostream>`  | Includes I/O stream library (even if unused) |
| `using namespace std;` | Optional shortcut to avoid `std::` prefix    |
| `int main() { ... }`   | Starting point of every C++ program          |
| `return 0;`            | Signals success to the OS                    |

> 🔸 Even without any logic or output, this is a valid, compilable program.

---

## 🔸 Python Boilerplate Code (No Output)

```python
def main():
    pass  # Placeholder for empty function

if __name__ == "__main__":
    main()
```

---

### 🔍 Notes Explanation – Python

| Line                         | Purpose                                                     |
| ---------------------------- | ----------------------------------------------------------- |
| `def main():`                | Defines the main function (like C++ `main`)                 |
| `pass`                       | Placeholder to make the function syntactically correct      |
| `if __name__ == "__main__":` | Checks if the file is run directly (not imported as module) |
| `main()`                     | Calls the main function                                     |

> 🔸 This is the minimal and clean setup for a script in Python.

---

## 🔸 Summary Table

| Feature          | C++                     | Python                             |
| ---------------- | ----------------------- | ---------------------------------- |
| Import/Include   | `#include <iostream>`   | No imports needed for empty script |
| Entry Point      | `int main()`            | `if __name__ == "__main__"`        |
| Function Body    | `{}` or comment block   | `pass` keyword                     |
| Output Statement | ❌ (Not included)        | ❌ (Not included)                   |
| Return Value     | `return 0;` (mandatory) | None required                      |

---

## 🔹 When to Use This?

✅ Use this boilerplate when:

* Starting a new C++ or Python file
* Practicing DSA problems
* Writing logic-only code without input/output
* Making templates for coding contests
* Creating utility scripts/modules

---

To add:

* ✅ Input boilerplate
* ✅ OOP boilerplate
* ✅ File reading/writing
* ✅ Competitive programming setup
