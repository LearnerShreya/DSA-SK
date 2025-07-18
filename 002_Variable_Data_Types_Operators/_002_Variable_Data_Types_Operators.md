# Variable Data Types Operators

---




## 🔹 1. Variables


### ◼ What is a Variable?

A **variable** is a **named memory location** used to **store data** that can be **changed during program execution**.

* Think of a variable as a **labeled container** in memory that stores a value like a number or text.
* A variable must be **declared** (and optionally initialized) before it is used.




### ◼ Rules for Naming Variables

A variable name is the **identifier** used to reference stored data in memory. Each programming language has specific rules for naming variables. Below are the general rules that apply in both C++ and Python, along with clarifications.


#### General Rules (Applicable to Both C++ and Python)

| Rule                    | Description                                                             |
| ----------------------- | ----------------------------------------------------------------------- |
| **Valid characters**    | Letters (`A–Z`, `a–z`), digits (`0–9`), and underscore (`_`)            |
| **Must begin with**     | A **letter** or an **underscore**                                       |
| **Cannot begin with**   | A **digit** (e.g., `1age` is invalid)                                   |
| **No special symbols**  | Symbols like `@`, `#`, `%`, `-`, `.`, space, etc., are **not allowed**  |
| **Case-sensitive**      | Yes. `Age`, `age`, and `AGE` are three different variables              |
| **Cannot be a keyword** | Reserved words like `int`, `float`, `if`, `class`, etc., cannot be used |
| **No whitespace**       | Variable names **cannot contain spaces** (`first name` is invalid)      |
| **Length**              | No fixed limit, but names should be short and meaningful                |


### ◼ Examples in C++

```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 21;            // Integer variable
    float height = 5.7;      // Float variable
    char grade = 'A';        // Character variable
    string name = "Shreya";  // String variable (requires #include <string>)
    bool isPassed = true;    // Boolean variable

    return 0;
}
```


### ◼ Examples in Python

```python
age = 21             # Integer variable
height = 5.7         # Float variable
grade = 'A'          # Character (actually a one-letter string)
name = "Shreya"      # String variable
is_passed = True     # Boolean variable
```

#### ◼ Difference Between C++ and Python Variables

| Feature              | C++                                             | Python                                          |
| -------------------- | ----------------------------------------------- | ----------------------------------------------- |
| Declaration Required | Yes – variables must be declared with a type    | No – type is automatically assigned at runtime  |
| Type System          | Statically typed (fixed data types)             | Dynamically typed (types can change at runtime) |
| Variable Definition  | `int x = 5;` (must specify type)                | `x = 5` (type inferred automatically)           |
| Type Change Allowed? | No – once declared with a type                  | Yes – you can reassign with a different type    |
| String Support       | `string name = "A";` (need `#include <string>`) | `name = "A"` (built-in support)                 |
| Boolean Values       | `true` / `false` (lowercase)                    | `True` / `False` (capitalized)                  |



#### ◼ Example of Type Flexibility (Python)

```python
x = 10         # x is int
x = "Shreya"   # x becomes string
x = 3.14       # x becomes float
```

This kind of redefinition is **not allowed in C++** unless type is changed explicitly using casting or overloading.

---

Great idea, Shreya. Adding the **size (in bytes)** column makes the notes more complete, especially for **C++**, where memory management matters.

Here's the **updated and enhanced version** of your **Data Types notes** with a clear **"Size" column** added:

---

## 🔹 2. Data Types

Data types define **the kind of data** a variable can store and how much **memory** it occupies.


### ◼ Broad Classification

```
Data Types
├── Primitive
│   ├── Integer
│   ├── Float
│   ├── Character
│   └── Boolean
├── Derived
│   ├── Array
│   ├── Function
│   └── Pointer
└── User-defined
    ├── Structure
    ├── Union
    └── Class
```



### ◼ C++ Data Types (with Size)

| Type      | Keyword                    | Example                   | Typical Size\* |
| --------- | -------------------------- | ------------------------- | -------------- |
| Integer   | `int`                      | `int age = 20;`           | 4 bytes        |
| Float     | `float`                    | `float pi = 3.14;`        | 4 bytes        |
| Double    | `double`                   | `double val = 5.12345;`   | 8 bytes        |
| Character | `char`                     | `char grade = 'A';`       | 1 byte         |
| Boolean   | `bool`                     | `bool flag = true;`       | 1 byte         |
| String    | `string` (from `<string>`) | `string name = "Shreya";` | Varies         |

> \*Size may vary depending on system and compiler (shown here for 64-bit systems using g++).

> C++ is **statically typed** – you must specify the data type before using a variable.


### ◼ Python Data Types (Dynamic – No Fixed Size)

| Type       | Example                | Description                   | Size (Approx.)\*    |
| ---------- | ---------------------- | ----------------------------- | ------------------- |
| Integer    | `a = 5`                | Whole numbers                 | ≥ 28 bytes          |
| Float      | `b = 3.14`             | Decimal numbers               | ≥ 24 bytes          |
| String     | `name = "Shreya"`      | Sequence of characters        | 49 + (1 per char)   |
| Boolean    | `flag = True`          | `True` or `False`             | 24 bytes            |
| List       | `nums = [1, 2, 3]`     | Ordered, mutable collection   | 64 bytes + elements |
| Tuple      | `t = (1, 2, 3)`        | Ordered, immutable collection | 48 bytes + elements |
| Set        | `s = {1, 2, 3}`        | Unordered, unique items       | 216+ bytes (varies) |
| Dictionary | `d = {'a': 1, 'b': 2}` | Key-value pairs               | 232+ bytes (varies) |

> \*Sizes vary by interpreter and system. Python is **dynamically typed**, so types and sizes are handled at runtime.


### ◼ Key Differences Between C++ and Python Data Types

| Feature                | C++                           | Python                                  |
| ---------------------- | ----------------------------- | --------------------------------------- |
| Typing system          | Static (must declare type)    | Dynamic (type auto-detected at runtime) |
| Type declaration       | Required (`int a = 10;`)      | Not required (`a = 10`)                 |
| Memory size            | Predictable (based on type)   | Varies (objects, references, overhead)  |
| Compilation            | Type checked at compile time  | Type checked at runtime                 |
| Built-in complex types | Limited (no list, dict, etc.) | Rich set (list, tuple, set, dict, etc.) |

---

# 🔹 3. Type Conversion (Type Casting)

Type Conversion means **converting one data type into another**. This is needed when different types are used together (e.g., int + float) or when you want to change how data is stored or processed.

---

## 🔸 Types of Type Conversion

| Type                    | Description                                                                    |
| ----------------------- | ------------------------------------------------------------------------------ |
| **Implicit Conversion** | Done automatically by the compiler/interpreter (also called **Type Coercion**) |
| **Explicit Conversion** | Done manually by the programmer (also called **Type Casting**)                 |

---

## 🔹 ◼ C++ – Type Conversion

### ✅ 1. **Implicit Type Conversion** (Automatic)

```cpp
int a = 5;
float b = a;  // int to float automatically
```

* No manual cast is needed.
* Lower to higher type is allowed (int → float, char → int).
* Might cause **precision loss** in reverse.

---

### ✅ 2. **Explicit Type Conversion** (Manual / Type Casting)

```cpp
int a = 10;
float b = (float) a;     // Using C-style casting
float c = float(a);      // Using function-style casting (C++ style)
```

### ✅ Type Casting Syntaxes in C++:

```cpp
(type)variable         // C-style
type(variable)         // Functional notation (recommended in modern C++)
```

📌 You can also use:

* `static_cast<type>(variable)` → Safer and modern C++ style

---

## 🔹 ◼ Python – Type Conversion

### ✅ 1. **Implicit Type Conversion**

```python
a = 5
b = 2.5
c = a + b  # int + float → float
print(c)   # Output: 7.5
```

### ✅ 2. **Explicit Type Conversion (Casting)**

```python
a = 10
b = float(a)     # int to float
c = str(a)       # int to string
d = int(4.7)     # float to int → Truncates decimal part
```

### ✅ Common Casting Functions in Python:

| Function            | Converts to      |
| ------------------- | ---------------- |
| `int()`             | Integer          |
| `float()`           | Floating point   |
| `str()`             | String           |
| `bool()`            | Boolean          |
| `list()`, `tuple()` | Collection Types |

---

## 🔸 Quick Summary Table

| Operation     | C++                   | Python         |
| ------------- | --------------------- | -------------- |
| Int to Float  | `float b = (float)a;` | `b = float(a)` |
| Float to Int  | `int x = (int)f;`     | `x = int(f)`   |
| Int to String | `to_string(a)`        | `str(a)`       |
| String to Int | `stoi("123")`         | `int("123")`   |

---

## 🔹 4. Operators

Operators are symbols that perform operations on variables and values.

---

### ◼ Arithmetic Operators

| Operator | Meaning        | C++ Example | Python Example |
| -------- | -------------- | ----------- | -------------- |
| `+`      | Addition       | `a + b`     | `a + b`        |
| `-`      | Subtraction    | `a - b`     | `a - b`        |
| `*`      | Multiplication | `a * b`     | `a * b`        |
| `/`      | Division       | `a / b`     | `a / b`        |
| `%`      | Modulo         | `a % b`     | `a % b`        |
| `**`     | Exponentiation | Not in C++  | `a ** b`       |
| `//`     | Floor Division | Not in C++  | `a // b`       |

---

### ◼ Assignment Operators

| Operator | Meaning             | Example (C++/Python) |
| -------- | ------------------- | -------------------- |
| `=`      | Assign value        | `a = 5`              |
| `+=`     | Add and assign      | `a += 2` (a = a + 2) |
| `-=`     | Subtract and assign | `a -= 1`             |
| `*=`     | Multiply and assign | `a *= 2`             |
| `/=`     | Divide and assign   | `a /= 2`             |
| `%=`     | Modulus and assign  | `a %= 3`             |

---

### ◼ Relational / Comparison Operators

Used to compare two values.

| Operator | Meaning          | Example  |
| -------- | ---------------- | -------- |
| `==`     | Equal to         | `a == b` |
| `!=`     | Not equal to     | `a != b` |
| `>`      | Greater than     | `a > b`  |
| `<`      | Less than        | `a < b`  |
| `>=`     | Greater or equal | `a >= b` |
| `<=`     | Less or equal    | `a <= b` |

---

### ◼ Logical Operators

| Operator | C++ Example | Python Example | Meaning     |   |     |          |            |
| -------- | ----------- | -------------- | ----------- | - | --- | -------- | ---------- |
| `&&`     | `a && b`    | `a and b`      | Logical AND |   |     |          |            |
| \`       |             | \`             | \`a         |   | b\` | `a or b` | Logical OR |
| `!`      | `!a`        | `not a`        | Logical NOT |   |     |          |            |

---

### ◼ Bitwise Operators

Works on bits.

| Operator | Meaning              | Example  |     |     |
| -------- | -------------------- | -------- | --- | --- |
| `&`      | AND                  | `a & b`  |     |     |
| \`       | \`                   | OR       | \`a | b\` |
| `^`      | XOR                  | `a ^ b`  |     |     |
| `~`      | NOT (1’s complement) | `~a`     |     |     |
| `<<`     | Left shift           | `a << 1` |     |     |
| `>>`     | Right shift          | `a >> 1` |     |     |

---

### ◼ Identity and Membership (Python Only)

| Operator | Meaning                  | Example            |
| -------- | ------------------------ | ------------------ |
| `is`     | Identity comparison      | `a is b`           |
| `is not` | Not the same object      | `a is not b`       |
| `in`     | Membership in collection | `5 in [1,2,3,4,5]` |
| `not in` | Not a member             | `10 not in list`   |

---

## 🔹 5. Constants

A **constant** is a variable whose value **cannot be changed** during execution.

* C++: Use `const` keyword

```cpp
const float PI = 3.1415;
```

* Python: No strict constants (by convention, constants are named in ALL CAPS)

```python
PI = 3.1415  # treated as constant
```

---

## 🔹 6. Input and Output

### ◼ C++

```cpp
#include<iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter age: ";
    cin >> age;
    cout << "You are " << age << " years old.";
    return 0;
}
```

### ◼ Python

```python
age = int(input("Enter age: "))
print("You are", age, "years old.")
```

---

## 🔹 7. Summary Table: Python vs C++

| Concept              | Python               | C++                    |
| -------------------- | -------------------- | ---------------------- |
| Variable Declaration | Dynamic (`x = 10`)   | Static (`int x = 10;`) |
| Type Conversion      | `int()`, `float()`   | `(int)`, `(float)`     |
| String Handling      | `"text"` or `'text'` | `#include<string>`     |
| No semicolons        | Yes                  | Required               |
| Indentation          | Syntax-sensitive     | Braces used            |

---
---

# Escape Sequences and Newline Handling

---

# Part 1: Escape Sequences

---

## What Are Escape Sequences?

An **escape sequence** is a combination of characters that represents something special inside a string.
It **starts with a backslash (`\`)** followed by a character.

Used to:

* Insert formatting like newlines and tabs
* Print characters that are otherwise hard to type (like quotes or backslashes)

### Example:

```cpp
cout << "Hello\nWorld";
```

```python
print("Hello\nWorld")
```

**Output in both languages:**

```
Hello
World
```

---

## Common Escape Sequences Table

| Escape Code | Name            | Meaning                                                 | Example              | Output or Effect             |
| ----------- | --------------- | ------------------------------------------------------- | -------------------- | ---------------------------- |
| `\n`        | Newline         | Moves to a new line                                     | `"Hello\nWorld"`     | Hello <br> World             |
| `\t`        | Horizontal Tab  | Adds horizontal space (like tab key)                    | `"Name:\tShreya"`    | Name:    Shreya              |
| `\\`        | Backslash       | Prints a single backslash                               | `"C:\\file"`         | C:\file                      |
| `\"`        | Double Quote    | Prints a double quote within a string                   | `"She said: \"Hi\""` | She said: "Hi"               |
| `\'`        | Single Quote    | Prints a single quote (useful in single-quoted strings) | `'It\'s OK'`         | It's OK                      |
| `\r`        | Carriage Return | Moves cursor to beginning of line (overwrites text)     | `"123\rABC"`         | ABC (overwrites 123)         |
| `\b`        | Backspace       | Deletes the previous character                          | `"Helloo\b"`         | Hello                        |
| `\a`        | Alert or Bell   | Produces a beep sound (C++ only, if system supports)    | `cout << "\a";`      | Beep sound                   |
| `\f`        | Form Feed       | Page break (used in printing, rarely seen today)        | `"A\fB"`             | A (new page) B               |
| `\v`        | Vertical Tab    | Vertical tab spacing                                    | `"Line1\vLine2"`     | Line1 (vertical space) Line2 |

---

## Example in C++

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Name:\tShreya\n";
    cout << "Quote: \"Learning never ends\"\n";
    cout << "Path: C:\\Users\\Shreya\n";
    cout << "123\rABC\n";
    cout << "Helloo\b\n";
    cout << "\a"; // Only works if system allows sound
    return 0;
}
```

**Output:**

```
Name:    Shreya
Quote: "Learning never ends"
Path: C:\Users\Shreya
ABC
Hello
(Beep sound)
```

---

## Example in Python

```python
print("Name:\tShreya")
print("Quote: \"Learning never ends\"")
print("Path: C:\\Users\\Shreya")
print("123\rABC")
print("Helloo\b")
```

**Output:**

```
Name:    Shreya
Quote: "Learning never ends"
Path: C:\Users\Shreya
ABC
Hello
```

---

# Part 2: Newline Handling and Print Control

---

## Output Behavior in C++

### 1. `\n` – Newline character

* Just adds a new line.
* Does **not flush** the output buffer.

```cpp
cout << "Line1\n";
cout << "Line2";
```

**Output:**

```
Line1
Line2
```

### 2. `endl` – End line and flush

* Adds a new line **and**
* **Flushes** the output buffer (forces immediate printing)

```cpp
cout << "Line1" << endl;
cout << "Line2";
```

**Output:**

```
Line1
Line2
```

Even if the system is slow to display output, `endl` forces it to show immediately.

---

## Output Behavior in Python

### 1. Default `print()` adds a newline

```python
print("Hello")
print("World")
```

**Output:**

```
Hello
World
```

### 2. `end=""` – Change what comes after the print

By default, `print()` ends with a newline (`\n`). You can change this.

```python
print("Hello", end="")
print("World")
```

**Output:**

```
HelloWorld
```

You can also use `end=" "` (space) or `end="\t"` (tab).

```python
print("Name:", end="\t")
print("Shreya")
```

**Output:**

```
Name:    Shreya
```

### 3. `flush=True` – Force immediate output

Normally, Python may wait before showing the output. To force it, use `flush=True`.

```python
import time

for i in range(3):
    print(i, end=" ", flush=True)
    time.sleep(1)
```

**Output (with delay):**

```
0 1 2
```

Without `flush=True`, numbers may not appear until the loop finishes.

---

## When to Use What?

| Situation                               | Use in C++             | Use in Python                     |
| --------------------------------------- | ---------------------- | --------------------------------- |
| Add a newline                           | `\n` or `endl`         | `\n` or just `print()`            |
| Add a tab                               | `\t`                   | `\t`                              |
| Include a double quote in text          | `\"`                   | `\"`                              |
| Include a backslash                     | `\\`                   | `\\`                              |
| Print without a newline                 | `cout << ...`          | `print(..., end="")`              |
| Add custom space/tab instead of newline | Not directly supported | `print(..., end=" ")`, `end="\t"` |
| Force immediate printing                | `endl` or `flush`      | `print(..., flush=True)`          |

---

# Summary

1. **Escape sequences** are used inside strings to format or add special characters.
2. `\n`, `\t`, `\\`, `\"`, `\'` are most commonly used and work the same in both C++ and Python.
3. C++ uses `endl` to add a newline and flush output.
4. Python uses `flush=True` to flush the output and `end="..."` to control what comes after the print.
5. If you want `endl` behavior in Python, write `print("text\n", flush=True)`.

---
