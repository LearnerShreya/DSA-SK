# Bitwise Operators Modifiers

---

# **C++ Essentials: Bitwise Operators, Modifiers, Scope, and Operator Precedence**

---

## **1. Bitwise Operators in C++**

Bitwise operators work directly on the **binary representation** of integers. These are extremely useful in performance-critical applications, competitive programming, embedded systems, and bit-level manipulation.

### **List of Bitwise Operators**

| Operator | Name        | Description                               | Example (Decimal) | Binary Example           | Result |
| -------- | ----------- | ----------------------------------------- | ----------------- | ------------------------ | ------ |
| `&`      | AND         | 1 only if both bits are 1                 | `5 & 3`           | `101 & 011` → `001`      | `1`    |
| `Or`     | OR          | 1 if at least one bit is 1                | `5 Or 3`          | `101 Or 011` → `111`     | `7`    |
| `^`      | XOR         | 1 if bits are different                   | `5 ^ 3`           | `101 ^ 011` → `110`      | `6`    |
| `~`      | NOT         | Flips each bit (1→0, 0→1)                 | `~5`              | `~00000101` → `11111010` | `-6`   |
| `<<`     | Left Shift  | Shifts bits to the left (multiplies by 2) | `5 << 1`          | `00000101` → `00001010`  | `10`   |
| `>>`     | Right Shift | Shifts bits to the right (divides by 2)   | `5 >> 1`          | `00000101` → `00000010`  | `2`    |

> Bitwise NOT `~` returns the 1's complement. Result appears negative due to 2's complement representation on signed integers.

---

## **2. Data Type Modifiers in C++**

Data type modifiers **alter the range or type** of primitive data types (mostly integers). They can reduce memory usage or expand the representable value range.

### **Modifiers Summary**

| Modifier    | Effect                                       | Example                | Why/When Needed (Use Case)                                                                          |
| ----------- | -------------------------------------------- | ---------------------- | --------------------------------------------------------------------------------------------------- |
| `short`     | Smaller range than `int` (typically 2 bytes) | `short a = 10;`        | Use when values are small (e.g., age, month, quantity) to save memory                               |
| `long`      | Larger than `int` (usually 4 or 8 bytes)     | `long a = 100000L;`    | For large numbers like file size, distance in meters, population count                              |
| `long long` | Very large range (64-bit)                    | `long long x = 1e18;`  | Needed in finance, astronomy, or scientific calculations involving very large values                |
| `signed`    | Can store both positive and negative values  | `signed int a = -5;`   | Useful when data can go negative (e.g., temperature, altitude change)                               |
| `unsigned`  | Only stores positive, larger upper limit     | `unsigned int a = 10;` | Use when only positive values are expected (e.g., age, count, ID) and you need a bigger upper limit |

---

### **Typical Sizes, Value Ranges & 2ⁿ (64-bit System)**

| Type                 | Size (bytes) | Value Range                                             | 2ⁿ Representation / Range Formula           |
| -------------------- | ------------ | ------------------------------------------------------- | ------------------------------------------- |
| `short int`          | 2            | –32,768 to 32,767                                       | $-2^{15} \text{ to } 2^{15}-1$              |
| `unsigned short`     | 2            | 0 to 65,535                                             | $0 \text{ to } 2^{16}-1$                    |
| `int`                | 4            | –2,147,483,648 to 2,147,483,647                         | $-2^{31} \text{ to } 2^{31}-1$              |
| `unsigned int`       | 4            | 0 to 4,294,967,295                                      | $0 \text{ to } 2^{32}-1$                    |
| `long int`           | 4 (or 8)     | –2,147,483,648 to 2,147,483,647 \*                      | $-2^{31} \text{ to } 2^{31}-1$ (if 4 bytes) |
| `unsigned long`      | 4 (or 8)     | 0 to 4,294,967,295 \*                                   | $0 \text{ to } 2^{32}-1$ (if 4 bytes)       |
| `long long int`      | 8            | –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | $-2^{63} \text{ to } 2^{63}-1$              |
| `unsigned long long` | 8            | 0 to 18,446,744,073,709,551,615                         | $0 \text{ to } 2^{64}-1$                    |

> 🔹 `sizeof(type)` in C++ gives exact size depending on compiler and platform (use `cout << sizeof(type)` to verify).
> 🔹 `long` may be 4 or 8 bytes depending on platform (especially on Linux vs Windows).
> 🔹 Unsigned types start from **0** and allow more positive range since no bit is reserved for sign.

---

## **3. Scope in C++ (Local vs Global)**

Scope refers to **where a variable is accessible** within the program.

### **Global Variable**

* Declared **outside any function**.
* Accessible **throughout** the program.

```cpp
int x = 10; // Global
void func() {
    cout << x; // Accesses global x
}
```

### **Local Variable**

* Declared **inside a function/block**.
* Accessible only within that block.

```cpp
void func() {
    int x = 5; // Local
    cout << x;
}
```

### **Shadowing**

* If a local variable has the same name as a global one, the local one takes precedence in that scope.

---

## **4. Operator Precedence in C++**

Operator precedence determines **which operators are evaluated first** when multiple appear in an expression.

Here’s a recreated version of the **Operator Precedence Table** (from your image):

### **Operator Precedence Table**

| Operators                 | Precedence Level | Associativity | 
| ------------------------- | ---------------- | ------------- |
| `!`, `+`, `–` (unary)     | First            | Right to Left |
| `*`, `/`, `%`             | Second           | Left to Right |
| `+`, `–`                  | Third            | Left to Right |
| `<`, `<=`, `>=`, `>`      | Fourth           | Left to Right |
| `==`, `!=`                | Fifth            | Left to Right |
| `&&`                      | Sixth            | Left to Right |
| `Or                       | Seventh          | Left to Right |
| `=` (assignment operator) | Last             | Right to Left |

### **Note on Bitwise Operators:**

Bitwise operators sit **between** the equality and logical operators in terms of precedence:

| Operator | Precedence             |
| -------- | ---------------------- |
| `&`      | After `==`, before `^` |
| `^`      | After `&`, before `Or` |
| `Or`     | After `^`, before `&&` |

### **Example:**

```cpp
int x = 5, y = 3;
int z = x & y + 2; // '+' is evaluated before '&'
```

Use parentheses to make expressions clear:

```cpp
int z = x & (y + 2);
```

---

## **5. Summary Tips**

* Use **bitwise operators** for performance and low-level logic.
* Use **modifiers** to optimize memory or handle large ranges.
* Understand **scope** to avoid variable shadowing bugs.
* Follow **precedence rules** or use parentheses to control evaluation.

---