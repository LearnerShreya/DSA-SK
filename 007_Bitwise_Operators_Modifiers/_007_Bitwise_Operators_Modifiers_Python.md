# Bitwise Operators Modifiers

---

# **Python Essentials: Bitwise Operators, Modifiers, Scope, and Operator Precedence**

---

## **1. Bitwise Operators in Python**

Bitwise operators in Python work on **binary (bit-level) representation** of integers. These are commonly used in **performance-critical logic**, **flags**, and **data masking**.

### **List of Bitwise Operators**

| Operator | Name        | Description                               | Example (Decimal)          | Binary Example           | Result |
| -------- | ----------- | ----------------------------------------- | -------------------------- | ------------------------ | ------ | 
| `&`      | AND         | 1 only if both bits are 1                 | `5 & 3`                    | `101 & 011` → `001`      | `1`    |
| `Or`     | OR          | 1 if at least one bit is 1                | `5 Or 3`                   | `101 Or 011`→`111`       | `7`    |
| `^`      | XOR         | 1 if bits are different                   | `5 ^ 3`                    | `101 ^ 011` → `110`      | `6`    |
| `~`      | NOT         | Inverts each bit (1→0, 0→1)               | `~5`                       | `~00000101` → `11111010` | `-6`   |
| `<<`     | Left Shift  | Shifts bits to the left (multiplies by 2) | `5 << 1`                   | `00000101` → `00001010`  | `10`   |
| `>>`     | Right Shift | Shifts bits to the right (divides by 2)   | `5 >> 1`                   | `00000101` → `00000010`  | `2`    |

> 🔸 Bitwise NOT `~x` gives `-(x+1)` due to 2’s complement in Python for signed integers.

---

## **2. Data Types & Number Modifiers in Python**

Python is **dynamically typed**, so you don’t declare types explicitly. But internally, Python handles:

* **Signed Integers (no limit)**
* **Booleans (subtype of int)**
* **Floating Points (64-bit IEEE 754)**
* **No `short`, `long`, `unsigned` like C++**

### **Integer Representation & Limits**

| Type    | Range                   | Note                                 |
| ------- | ----------------------- | ------------------------------------ |
| `int`   | Unlimited precision     | Auto-expands beyond 64-bit           |
| `bool`  | `True (1)`, `False (0)` | Used in logic and bitwise operations |
| `float` | ±1.8 × 10³⁰⁸ (approx)   | 64-bit precision                     |

> 🔹 Python does not overflow with large integers — it expands memory.
> 🔹 Use `bin(x)`, `hex(x)`, `oct(x)` for base conversions.

---

## **3. Variable Scope in Python**

Scope refers to the **visibility and lifetime** of a variable in a program.

### **Types of Scopes**

| Scope Type   | Description                                  |
| ------------ | -------------------------------------------- |
| **Local**    | Inside a function/block only                 |
| **Global**   | Declared outside all functions               |
| **Enclosed** | From enclosing function in nested functions  |
| **Built-in** | Predefined names (like `len`, `range`, etc.) |

### **Example:**

```python
x = 10  # Global

def func():
    x = 5  # Local
    print(x)  # 5
func()
print(x)      # 10
```

### **Global Keyword**

To modify a global variable inside a function:

```python
x = 10
def change():
    global x
    x = 20
```

---

## **4. Operator Precedence in Python**

Operator precedence defines **which operator is evaluated first**.

### **Python Operator Precedence Table**

| Precedence | Operators                          | Associativity |
| ---------- | ---------------------------------- | ------------- |
| Highest    | `()` (parentheses)                 | N/A           |
|            | `**` (exponentiation)              | Right to Left |
|            | `+x`, `-x`, `~x` (unary operators) | Right to Left |
|            | `*`, `/`, `//`, `%`                | Left to Right |
|            | `+`, `-`                           | Left to Right |
|            | `<<`, `>>`                         | Left to Right |
|            | `&`                                | Left to Right | 
|            | `^`                                | Left to Right |
|            | `Or`                               | Left to Right |
|            | Comparison (`<`, `<=`, `==`, etc.) | Left to Right |
|            | `not`                              | Right to Left |
|            | `and`                              | Left to Right |
|            | `or`                               | Left to Right |
| Lowest     | `=`, `+=`, `-=`, etc.              | Right to Left |

### **Example:**

```python
x = 5
y = 3
z = x & y + 2   # '+' is evaluated first
# Equivalent to: x & (y + 2)
```

Use parentheses for clarity and safety.

---

## **5. Summary Tips**

✅ Use **bitwise ops** for flags, masks, low-level manipulations.
✅ Python’s `int` has **no overflow**, but be careful with memory.
✅ Understand **scopes** (`global`, `local`, etc.) to avoid confusion.
✅ Use **parentheses** to override operator precedence and write clean code.
✅ Use `bin()`, `int('binary_str', 2)` etc. for binary manipulations.

---