
### ✅ Summary:

| Concept              | Magic Line To Remember                                                             |
| -------------------- | ---------------------------------------------------------------------------------- |
| Pass by Value        | Immutable Data Types → Behave Like Pass by Value (Safe Copy)                       |
| Pass by Reference    | Mutable Data Types → Behave Like Pass by Reference (Changes Original)              |
| Function Overloading | No Traditional Overloading in Python → Use Default Arguments / \*args / \*\*kwargs |
| Function Overriding  | Child Changes Parent’s Function (Inheritance + Overriding)                         |

---

### ✅ Super Shortcut to Remember:

> **Immutable Data** → Safe (Copy-like)
> **Mutable Data** → Changes Original
> No Classic Overloading — Use Default / \*args / \*\*kwargs
> Function Overriding → Same as C++ (Child Wins!)

---

## ✅ 🪄 Brain Tattoo Tip:

**In Python:**

* Immutable → Pass by Value-like (Safe)
* Mutable → Pass by Reference-like (Can Change)
* No Classic Overloading → Use Default Args / \*args / \*\*kwargs
* Overriding → Same as C++ (Inheritance + Redefinition)

---

---

## ✅ **1. Pass by Value & Pass by Reference in Python**

### ✅ Imagine This:

> You ask your friend to solve a task.

* Immutable Type (int, str, tuple) → Behaves like Pass by Value
* Mutable Type (list, dict, set) → Behaves like Pass by Reference

---

### ✅ Pass by Value-Like (Immutable Types: int, str, tuple)

#### 🔹 Example:

```python
def changeValue(x):
    x = 50

num = 10
changeValue(num)
print(num)  # Output: 10
```

---

### ✅ Step-by-Step Dry Run (Immutable Type):

| Step | Statement                  | Value of `num` in main | Value of `x` in function |
| ---- | -------------------------- | ---------------------- | ------------------------ |
| 1    | `num = 10`                 | 10                     | —                        |
| 2    | Call `changeValue(num)`    | 10                     | x = Copy of 10           |
| 3    | Inside function → `x = 50` | 10                     | x becomes 50 (copy only) |
| 4    | Function ends              | 10                     | —                        |
| 5    | Print `num`                | Prints **10**          | —                        |

✅ Output: **10**
(*Original variable stays safe — behaves like pass by value.*)

---

#### ✅ Key Point:

> Immutable Data → Safe → No change to original variable.

---

### ✅ Pass by Reference-Like (Mutable Types: list, dict, set)

#### 🔹 Example:

```python
def changeList(lst):
    lst[0] = 50

numbers = [10, 20, 30]
changeList(numbers)
print(numbers)  # Output: [50, 20, 30]
```

---

### ✅ Step-by-Step Dry Run (Mutable Type):

| Step | Statement                       | Value of `numbers` in main | Value of `lst` in function |
| ---- | ------------------------------- | -------------------------- | -------------------------- |
| 1    | `numbers = [10, 20, 30]`        | \[10, 20, 30]              | —                          |
| 2    | Call `changeList(numbers)`      | Refers to same list        | \[10, 20, 30]              |
| 3    | Inside function → `lst[0] = 50` | \[50, 20, 30]              | Changes same list          |
| 4    | Function ends                   | \[50, 20, 30]              | —                          |
| 5    | Print `numbers`                 | Prints **\[50, 20, 30]**   | —                          |

✅ Output: **\[50, 20, 30]**
(*Original list changed — behaves like pass by reference.*)

---

#### ✅ Key Point:

> Mutable Data → Can Change Original → Acts like pass by reference.

---

### ✅ Summary Table (Python Behavior):

| Data Type                   | Behavior                         | Affects Original? |
| --------------------------- | -------------------------------- | ----------------- |
| Immutable (int, str, tuple) | Pass by Value-like (Safe)        | No                |
| Mutable (list, dict, set)   | Pass by Reference-like (Changes) | Yes               |

---

### ✅ Magic Trick to Remember:

> ✨ Immutable → Safe
> ✨ Mutable → Changes Original

---

---

## ✅ **2. Function Overloading in Python**

### ✅ Key Fact:

> Python does NOT support traditional function overloading (like C++).
> Instead, it uses:

1. **Default Parameters**
2. **Variable Arguments** (\*args, \*\*kwargs)

---

#### ✅ Example (Python-Style Overloading):

```python
def greet(name=None):
    if name:
        print("Hello,", name)
    else:
        print("Hello!")

greet()          # Output: Hello!
greet("Shreya")  # Output: Hello, Shreya!
```

---

#### ✅ Key Point:

> Python achieves "overloading" using **default arguments** or **variable arguments**.

---

#### ✅ Magic Line to Remember:

> \*No Traditional Overloading — Use Default Args or \*args / \**kwargs!*

---

---

## ✅ **3. Function Overriding in Python (Inheritance Concept)**

### ✅ What is it?

> When a child class **redefines** a function of its parent class.

---

#### ✅ Example:

```python
class Animal:
    def sound(self):
        print("Animal makes a sound")

class Dog(Animal):
    def sound(self):
        print("Dog barks")

d = Dog()
d.sound()  # Output: Dog barks
```

---

#### ✅ Key Point:

> Child class function **replaces** parent class function when called.

---

#### ✅ Rules:

1. Function name must be **same**.
2. Requires **inheritance**.
3. Happens automatically in Python.

---

#### ✅ Magic Line to Remember:

> *Child Changes Parent’s Function → Function Overriding!*

---

---

## ✅ Quick Comparison Table (Python Version):

| Feature             | Function Overloading                                   | Function Overriding                       |
| ------------------- | ------------------------------------------------------ | ----------------------------------------- |
| Concept             | No Traditional Overloading — Use Default Args / \*args | Child function replaces parent’s function |
| Purpose             | Handle different numbers of arguments                  | Change behavior in child class            |
| Inheritance Needed? | No                                                     | Yes                                       |
| Compile/Run Time?   | Runtime (Dynamic Typing)                               | Runtime (Dynamic Typing)                  |

---

---

### ✅ Final Magic Trick to Remember (Python):

> ✨ Immutable → Safe
> ✨ Mutable → Changes
> ✨ No Overloading → Use Defaults / \*args
> ✨ Overriding → Same as C++, Child Wins!

---
