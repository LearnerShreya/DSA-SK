
# Conditional Statements Loops

# ✅ MASTER NOTES: LOOPS (Part 2)

---

## 📍 A. What Are Loops?

Loops allow you to **repeat a block of code** multiple times.

### 🔹 Use Cases:

* Repeating tasks (e.g., print numbers 1 to 100)
* Iterating over data (lists, strings, arrays)
* Pattern building
* Searching, summing, counting

---

## 📍 B. Types of Loops

| Type       | C++ | Python | When to Use                        |
| ---------- | --- | ------ | ---------------------------------- |
| `for`      | ✅   | ✅      | Known number of iterations         |
| `while`    | ✅   | ✅      | Unknown number of iterations       |
| `do-while` | ✅   | ❌      | Run at least once, then check      |
| `nested`   | ✅   | ✅      | Patterns, matrix-type problems     |
| `break`    | ✅   | ✅      | Exit a loop early                  |
| `continue` | ✅   | ✅      | Skip one iteration                 |
| `pass`     | ❌   | ✅      | Placeholder, does nothing (Python) |

---

## 📍 C. 1. `for` Loop

---

### 🔹 1.1 Syntax

**C++**

```cpp
for (initialization; condition; increment) {
    // code
}
```

**Python**

```python
for variable in range(start, stop, step):
    # code
```

---

### 🔹 1.2 Print Numbers 1 to 5

**C++**

```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}
// Output: 1 2 3 4 5
```

**Python**

```python
for i in range(1, 6):
    print(i, end=" ")
# Output: 1 2 3 4 5
```

---

### 🔹 1.3 Sum of 1 to N (10)

**C++**

```cpp
int sum = 0;
for (int i = 1; i <= 10; i++) {
    sum += i;
}
cout << sum;
// Output: 55
```

**Python**

```python
sum = 0
for i in range(1, 11):
    sum += i
print(sum)
# Output: 55
```

---

## 📍 D. 2. `while` Loop

---

### 🔹 2.1 Syntax

**C++**

```cpp
while (condition) {
    // code
}
```

**Python**

```python
while condition:
    # code
```

---

### 🔹 2.2 Print 1 to 5 using `while`

**C++**

```cpp
int i = 1;
while (i <= 5) {
    cout << i << " ";
    i++;
}
// Output: 1 2 3 4 5
```

**Python**

```python
i = 1
while i <= 5:
    print(i, end=" ")
    i += 1
# Output: 1 2 3 4 5
```

---

## 📍 E. 3. `do-while` Loop (C++ Only)

---

### 🔹 3.1 Syntax

**C++**

```cpp
do {
    // code
} while (condition);
```

> Python doesn’t have `do-while`, but you can simulate using `while True` + `break`

---

### 🔹 3.2 Example

**C++**

```cpp
int i = 1;
do {
    cout << i << " ";
    i++;
} while (i <= 5);
// Output: 1 2 3 4 5
```

---

## 📍 F. 4. `break`, `continue`, and `pass`

---

### 🔹 4.1 `break`: exit the loop early

**C++**

```cpp
for (int i = 1; i <= 5; i++) {
    if (i == 3) break;
    cout << i << " ";
}
// Output: 1 2
```

**Python**

```python
for i in range(1, 6):
    if i == 3:
        break
    print(i, end=" ")
# Output: 1 2
```

---

### 🔹 4.2 `continue`: skip current iteration

**C++**

```cpp
for (int i = 1; i <= 5; i++) {
    if (i == 3) continue;
    cout << i << " ";
}
// Output: 1 2 4 5
```

**Python**

```python
for i in range(1, 6):
    if i == 3:
        continue
    print(i, end=" ")
# Output: 1 2 4 5
```

---

### 🔹 4.3 `pass` (Python only): placeholder

**Python**

```python
for i in range(1, 6):
    if i == 3:
        pass  # do nothing
    print(i, end=" ")
# Output: 1 2 3 4 5
```

---

## 📍 G. 5. Nested Loops

---

### 🔹 Use:

Used in pattern printing, 2D problems, grids.

---

### 🔹 Example: Rectangle of Stars (3x5)

**C++**

```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 5; j++) {
        cout << "*";
    }
    cout << endl;
}
/*
Output:
*****
*****
*****
*/
```

**Python**

```python
for i in range(3):
    for j in range(5):
        print("*", end="")
    print()
# Output:
# *****
# *****
# *****
```

---

## 📍 H. 6. Loop Dry Run (Visual Flow)

**Python Code**

```python
for i in range(1, 4):
    for j in range(1, 3):
        print(i, j)
```

**Dry Run Table**

| i | j | Output |
| - | - | ------ |
| 1 | 1 | 1 1    |
| 1 | 2 | 1 2    |
| 2 | 1 | 2 1    |
| 2 | 2 | 2 2    |
| 3 | 1 | 3 1    |
| 3 | 2 | 3 2    |

---

## 📍 I. Common Mistakes

| Mistake                    | Fix                                          |
| -------------------------- | -------------------------------------------- |
| Forgetting to increment    | Add `i++` or `i += 1` in loop                |
| Infinite loop accidentally | Always make sure condition will become false |
| Missing `:` in Python      | Always add `:` after loop header             |
| Using wrong range          | `range(1, 6)` prints 1 to 5, not 6           |
| Not using `{}` in C++      | Always use braces even for one line          |

---

## 📍 J. Summary Table

| Concept    | C++ Example              | Python Example       |
| ---------- | ------------------------ | -------------------- |
| `for` loop | `for(int i=0; i<n; i++)` | `for i in range(n):` |
| `while`    | `while (cond) {}`        | `while cond:`        |
| `do-while` | `do {...} while(cond);`  | Not available        |
| `break`    | `break;`                 | `break`              |
| `continue` | `continue;`              | `continue`           |
| `pass`     | Not available            | `pass`               |

---
