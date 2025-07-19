# Conditional Statements Loops

# ✅ MASTER NOTES: CONDITIONAL STATEMENTS (Part 1)

## 📍 A. PURPOSE

Conditional statements help us **make decisions** in our program based on **some condition (True/False)**.

Use when:

* You want your program to take **different actions** depending on user input or data.
* You're checking for **validity**, comparisons, choices, etc.

---

## 📍 B. TYPES OF CONDITIONAL STATEMENTS

| Statement Type     | Description                                  |
| ------------------ | -------------------------------------------- |
| `if`               | Executes code if condition is true           |
| `if-else`          | Runs one block if true, another if false     |
| `if-else if-else`  | Checks multiple conditions in sequence       |
| `nested if`        | if inside if — for dependent conditions      |
| `ternary operator` | Short form of `if-else` (for assignments)    |
| `switch`           | Used in C++ for multiple constant conditions |

✅ Covered in both **C++ and Python**, except `switch` (not available in Python)

---

## 📍 C. OPERATORS USED IN CONDITIONS

| Type       | Symbols C++ & Python                        | Use Case         |                                              |                    |
| ---------- | ------------------------------------------- | ---------------- | -------------------------------------------- | ------------------ |
| Comparison | `==`, `!=`, `<`, `>`, `<=`, `>=`            | Compare values   |                                              |                    |
| Logical    | `&&`, \`                                    |                  | `, `!`(C++) <br>`and`, `or`, `not\` (Python) | Combine conditions |
| Assignment | `=`                                         | Assign value     |                                              |                    |
| Ternary    | `?:` (C++) <br> `x if cond else y` (Python) | Inline decisions |                                              |                    |

---

## 📍 D. DETAILED BREAKDOWN WITH EXAMPLES

### 1. `if` Statement

**Use:** When you want to **execute code only if the condition is true**.

**C++ Syntax**

```cpp
if (condition) {
    // block runs if true
}
```

**Python Syntax**

```python
if condition:
    # block runs if true
```

**Example**

**C++**

```cpp
int age = 20;
if (age >= 18) {
    cout << "Eligible to vote";
}
// Output: Eligible to vote
```

**Python**

```python
age = 20
if age >= 18:
    print("Eligible to vote")
# Output: Eligible to vote
```

---

### 2. `if-else` Statement

**Use:** When you need **either-or** control.

**C++ Syntax**

```cpp
if (condition) {
    // if block
} else {
    // else block
}
```

**Python Syntax**

```python
if condition:
    # if block
else:
    # else block
```

**Example**

**C++**

```cpp
int num = 7;
if (num % 2 == 0) {
    cout << "Even";
} else {
    cout << "Odd";
}
// Output: Odd
```

**Python**

```python
num = 7
if num % 2 == 0:
    print("Even")
else:
    print("Odd")
# Output: Odd
```

---

### 3. `if-else if-else` / `if-elif-else`

**Use:** When you have **multiple decisions to make**.

**C++ Syntax**

```cpp
if (a > b) {
    // block 1
} else if (a == b) {
    // block 2
} else {
    // block 3
}
```

**Python Syntax**

```python
if a > b:
    # block 1
elif a == b:
    # block 2
else:
    # block 3
```

**Example**

**C++**

```cpp
int marks = 60;
if (marks >= 90) {
    cout << "A Grade";
} else if (marks >= 75) {
    cout << "B Grade";
} else if (marks >= 50) {
    cout << "C Grade";
} else {
    cout << "Fail";
}
// Output: C Grade
```

**Python**

```python
marks = 60
if marks >= 90:
    print("A Grade")
elif marks >= 75:
    print("B Grade")
elif marks >= 50:
    print("C Grade")
else:
    print("Fail")
# Output: C Grade
```

---

### 4. Nested `if`

**Use:** When conditions **depend** on each other.

**Example**

**C++**

```cpp
int age = 25;
char gender = 'M';

if (age > 18) {
    if (gender == 'M') {
        cout << "Adult Male";
    } else {
        cout << "Adult Female";
    }
}
// Output: Adult Male
```

**Python**

```python
age = 25
gender = 'M'

if age > 18:
    if gender == 'M':
        print("Adult Male")
    else:
        print("Adult Female")
# Output: Adult Male
```

---

### 5. Ternary Operator

**Use:** Compact form of `if-else` for simple assignment or output.

**C++ Syntax**

```cpp
int max = (a > b) ? a : b;
```

**Python Syntax**

```python
max = a if a > b else b
```

**Example**

**C++**

```cpp
int a = 10, b = 20;
cout << ((a > b) ? "A is greater" : "B is greater");
// Output: B is greater
```

**Python**

```python
a = 10
b = 20
print("A is greater" if a > b else "B is greater")
# Output: B is greater
```

---

### 6. `switch` Statement (C++ Only)

**Use:** Multi-condition check for fixed values (numbers, chars)

**Syntax**

```cpp
switch(expression) {
    case value1:
        // code
        break;
    case value2:
        // code
        break;
    default:
        // default code
}
```

**Example**

```cpp
int day = 3;
switch (day) {
    case 1: cout << "Monday"; break;
    case 2: cout << "Tuesday"; break;
    case 3: cout << "Wednesday"; break;
    default: cout << "Invalid";
}
// Output: Wednesday
```

Note: **Python doesn’t have `switch`. Use `if-elif-else` instead.**

---

## 📍 E. Best Practices

| Tip                                  | Why                                   |
| ------------------------------------ | ------------------------------------- |
| Always use `{}` in C++               | Avoid errors with multiple statements |
| Indentation is mandatory in Python   | It's part of the syntax               |
| Don't confuse `=` and `==`           | `=` assigns, `==` compares            |
| Ternary is for simple use cases only | Use full `if-else` for complex logic  |
| `switch` only for constant values    | Not for ranges or logic expressions   |

---