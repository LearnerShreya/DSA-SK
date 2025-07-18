# **📘 Complete Notes on Operators**

Operators are special symbols used to perform operations on variables and values.

---

## 🔰 Types of Operators (Based on Operands)

| Type    | Description                | Example           |
| ------- | -------------------------- | ----------------- |
| Unary   | Operates on **1** operand  | `-a`, `++a`, `!a` |
| Binary  | Operates on **2** operands | `a + b`, `a > b`  |
| Ternary | Operates on **3** operands | `a > b ? x : y`   |

---

## ✅ 1. Arithmetic Operators

Used for **mathematical operations**.

| Operator | Meaning             | Example (a=10, b=3) | Result    |
| -------- | ------------------- | ------------------- | --------- |
| `+`      | Addition            | `a + b`             | 13        |
| `-`      | Subtraction         | `a - b`             | 7         |
| `*`      | Multiplication      | `a * b`             | 30        |
| `/`      | Division            | `a / b`             | 3 or 3.33 |
| `%`      | Modulus (Remainder) | `a % b`             | 1         |
| `**`     | Exponent (Python)   | `a ** b`            | 1000      |
| `//`     | Floor Division (Py) | `a // b`            | 3         |

---

## ✅ 2. Relational (Comparison) Operators

Used to **compare values**, returns **boolean**.

| Operator | Meaning          | Example (`a=10`, `b=3`) | Output |
| -------- | ---------------- | ----------------------- | ------ |
| `==`     | Equal to         | `a == b`                | false  |
| `!=`     | Not equal to     | `a != b`                | true   |
| `>`      | Greater than     | `a > b`                 | true   |
| `<`      | Less than        | `a < b`                 | false  |
| `>=`     | Greater or equal | `a >= b`                | true   |
| `<=`     | Less or equal    | `a <= b`                | false  |

---


## ✅ 3. Logical Operators

Used with **boolean logic** (true/false).

| Operator                    | Meaning       | Example (`a=10`, `b=3`)    | Result |
|----------------------------|---------------|------------------------|--------|
| `&&`                       | Logical AND   | `(a > 5 && b < 5)`     | true   |
| <code>&#124;&#124;</code>  | Logical OR    | <code>a &lt; 5 &#124;&#124; b &lt; 5</code> | true |
| `!`                        | Logical NOT   | `!(a > 5)`             | false  |

> 🔹 In Python, use `and`, `or`, and `not` instead of `&&`, `||`, and `!`

---

## ✅ 4. Assignment Operators

Used to **assign or update** values.

| Operator | Meaning                | Example     | Same As         |
|----------|------------------------|-------------|-----------------|
| `=`      | Assign                 | `a = 10`    | -               |
| `+=`     | Add and assign         | `a += 5`    | `a = a + 5`     |
| `-=`     | Subtract and assign    | `a -= 2`    | `a = a - 2`     |
| `*=`     | Multiply and assign    | `a *= 3`    | `a = a * 3`     |
| `/=`     | Divide and assign      | `a /= 2`    | `a = a / 2`     |
| `//=`    | Floor divide and assign| `a //= 2`   | `a = a // 2`    |
| `%=`     | Modulus and assign     | `a %= 3`    | `a = a % 3`     |
| `**=`    | Power and assign (Py)  | `a **= 2`   | `a = a ** 2`    |


---

## ✅ 5. Unary Operators

Operate on **single operand**.

| Operator  | Meaning     | Example (`a=5`)      | Result |
| --------- | ----------- | -------------------- | ------ |
| `+`       | Unary plus  | `+a`                 | 5      |
| `-`       | Unary minus | `-a`                 | -5     |
| `++`      | Increment   | `++a`, `a++`         | 6      |
| `--`      | Decrement   | `--a`, `a--`         | 4      |
| `!`/`not` | Logical NOT | `!true` / `not True` | false  |

> 🔹 `++`/`--` not in Python.

---

## ✅ 6. Bitwise Operators

Works on **binary bits** (integers only).  
Assume: `a = 5 (0101)` and `b = 3 (0011)`

| Operator            | Name         | Example              | Binary Operation                     | Result |
|---------------------|--------------|-----------------------|--------------------------------------|--------|
| `&`                 | AND          | `a & b`               | `0101 & 0011 = 0001`                 | `1`    |
| <code>&#124;</code> | OR           | <code>a &#124; b</code> | <code>0101 &#124; 0011 = 0111</code> | `7` |
| `^`                 | XOR          | `a ^ b`               | `0101 ^ 0011 = 0110`                 | `6`    |
| `~`                 | NOT          | `~a`                  | `~0101 = 1010` (2’s comp of 6)       | `-6`   |
| `<<`                | Left Shift   | `a << 1`              | `0101 << 1 = 1010`                   | `10`   |
| `>>`                | Right Shift  | `a >> 1`              | `0101 >> 1 = 0010`                   | `2`    |

---

## ✅ 7. Ternary Operator

Shortcut for **if-else**.

**Syntax (C++/Java):** `(condition) ? true_value : false_value;`

**Example:**

```cpp
int max = (a > b) ? a : b;
```

> 🔹 Python: `x if condition else y`

---

## ✅ 8. Miscellaneous Operators

| Operator | Use                         | Example          |
| -------- | --------------------------- | ---------------- |
| `sizeof` | Size of datatype (C/C++)    | `sizeof(int)`    |
| `type()` | Type check (Python)         | `type(10)` → int |
| `&`      | Address of variable (C/C++) | `&a`             |
| `*`      | Pointer dereference (C/C++) | `*ptr`           |
| `in`     | Membership (Python)         | `'a' in 'apple'` |
| `is`     | Identity check (Python)     | `a is b`         |

---

## ✅ 9. Operator Precedence and Associativity

Determines the **order of evaluation** in expressions with multiple operators.

> 🔹 Precedence (Highest to Lowest)

| Precedence Level | Operators                                               | Associativity    |
|------------------|---------------------------------------------------------|------------------|
| 1                | `()` (parentheses)                                      | Left to Right    |
| 2                | `++`, `--`, `+`, `-` (unary), `!`, `~`                  | Right to Left    |
| 3                | `*`, `/`, `%`                                           | Left to Right    |
| 4                | `+`, `-`                                                | Left to Right    |
| 5                | `<`, `<=`, `>`, `>=`                                    | Left to Right    |
| 6                | `==`, `!=`                                              | Left to Right    |
| 7                | `&` (bitwise AND)                                       | Left to Right    |
| 8                | `^` (bitwise XOR)                                       | Left to Right    |
| 9                | <code>&#124;</code> (bitwise OR)                        | Left to Right    |
| 10               | <code>&amp;&amp;</code> (logical AND)                   | Left to Right   |
| 11               | <code>&#124;&#124;</code> (logical OR)                  | Left to Right   |
| 12               | `?:` (ternary conditional)                              | Right to Left    |
| 13               | `=`, `+=`, `-=`, `*=`, `/=`, `%=`, etc.                 | Right to Left    |
| 14               | `,` (comma)                                             | Left to Right    |

> ℹ️ Use `()` to control evaluation order explicitly.


---


## 📌 Summary Table

| Category      | Examples                                             | Purpose               |
|---------------|------------------------------------------------------|------------------------|
| Unary         | `-a`, `!a`                                           | One operand            |
| Binary        | `a + b`, `a > b`                                     | Two operands           |
| Ternary       | `(a > b) ? a : b`                                    | Conditional (3 parts)  |
| Arithmetic    | `+`, `-`, `*`, `/`, `%`                              | Math operations        |
| Relational    | `==`, `>`, `!=`                                      | Compare values         |
| Logical       | <code>&amp;&amp;</code>, <code>&#124;&#124;</code>, `!` | Boolean logic          |
| Assignment    | `=`, `+=`, `*=`, `-=`                                | Assign/update values   |
| Bitwise       | `&`, <code>&#124;</code>, `^`, `~`                   | Bit-level operations   |
| Miscellaneous | `sizeof`, `in`, `type()`                             | Special usage          |
| Precedence    | All of the above in priority order                   | Defines priority       |

---

## ✅ 10. **Comma Operator**

* Used to **separate multiple expressions**, evaluates **left to right**, returns the **value of the last**.

| Operator | Use                  | Example              | Result |
| -------- | -------------------- | -------------------- | ------ |
| `,`      | Separate expressions | `a = (b = 3, b + 2)` | `5`    |

> 🔹 Mostly used in `for` loops in C/C++:

```cpp
for(int i=0, j=10; i<j; i++, j--) { ... }
```

---

## ✅ 11. **Scope Resolution Operator (`::`)** – C++

* Used to **access global variables**, class members, or namespace members.

| Operator | Use              | Example               |
| -------- | ---------------- | --------------------- |
| `::`     | Scope resolution | `::x`, `Class::fun()` |

---

## ✅ 12. **Pointer Operators** – C/C++

* Already partially included, but here’s a clearer structure:

| Operator | Name           | Use                       | Example     |
| -------- | -------------- | ------------------------- | ----------- |
| `*`      | Dereference    | Access value via pointer  | `*ptr`      |
| `&`      | Address-of     | Get address of a variable | `&a`        |
| `->`     | Arrow Operator | Access member via pointer | `ptr->data` |

---

## ✅ 13. **Member Access Operators**

| Operator | Use                                   | Example    |
| -------- | ------------------------------------- | ---------- |
| `.`      | Access object/struct/class member     | `obj.var`  |
| `->`     | Access member using pointer to object | `ptr->var` |

---

## ✅ 14. **String Operators** – Python

Python allows direct string operations:

| Operator | Description   | Example            | Output        |
| -------- | ------------- | ------------------ | ------------- |
| `+`      | Concatenation | `'Hi' + ' Shreya'` | `"Hi Shreya"` |
| `*`      | Repetition    | `'Hi'*3`           | `"HiHiHi"`    |

---

## ✅ 15. **Identity & Membership (Python)** – Already listed, but to emphasize:

| Operator | Type       | Example              | Result       |
| -------- | ---------- | -------------------- | ------------ |
| `in`     | Membership | `'a' in 'apple'`     | `True`       |
| `not in` | Membership | `'z' not in 'apple'` | `True`       |
| `is`     | Identity   | `a is b`             | `True/False` |
| `is not` | Identity   | `a is not b`         | `True/False` |

---

## ✅ 16. **Null Coalescing Operator** – C#, PHP, etc.

Used to return the first non-null operand.

| Operator | Language | Use                         | Example       |
| -------- | -------- | --------------------------- | ------------- |
| `??`     | C#, PHP  | Return first non-null value | `x = a ?? b;` |

---

## ✅ 17. **Elvis Operator (`?:`)** – Kotlin, Groovy

Shortcut for null checks.

| Operator | Use                 | Example        |
| -------- | ------------------- | -------------- |
| `?:`     | Null check shortcut | `val = a ?: 0` |

---

## ✅ 18. **Safe Navigation Operator (`?.`)** – Kotlin, C\#

Used to **safely access** members if object is not null.

| Operator | Use                     | Example         |
| -------- | ----------------------- | --------------- |
| `?.`     | Null-safe member access | `obj?.method()` |

---

## ✅ 19. **Spread Operator** – JavaScript, Python

| Operator  | Language   | Use                              | Example                 |
| --------- | ---------- | -------------------------------- | ----------------------- |
| `...`     | JavaScript | Spread or rest in arrays/objects | `[...arr1, ...arr2]`    |
| `*`, `**` | Python     | Argument unpacking               | `func(*args, **kwargs)` |

---

## 🧠 TL;DR – New Categories to Add in Summary Table

| Category         | Examples                  | Purpose                       |
| ---------------- | ------------------------- | ----------------------------- |
| Comma            | `a = (b = 3, b + 2)`      | Evaluate multiple expressions |
| Scope Resolution | `::x`, `Class::func()`    | Global/class access (C++)     |
| Pointer          | `&`, `*`, `->`            | Address and dereference       |
| Member Access    | `.`, `->`                 | Object/Struct access          |
| String           | `'Hi' + 'There'`, `'a'*3` | String ops (Python)           |
| Null/Optional    | `??`, `?:`, `?.`          | Null safety (Kotlin/C#/PHP)   |
| Spread/Unpack    | `...`, `*args`            | Expand iterable (JS/Py)       |

---
