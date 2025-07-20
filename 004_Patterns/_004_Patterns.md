# Patterns


## 🧠 **What is Pattern Printing?**

In programming, **pattern printing** means printing shapes or figures (made of `*`, numbers, or alphabets) using **loops**.
It helps strengthen your understanding of:

* **Nested Loops**
* **Conditionals**
* **Dry Run Thinking**
* **Time Complexity (later)**

---

## 🔗 **Building Blocks of Pattern Problems**

To crack any pattern problem, you need:

```
1. Observation
2. Row-wise Dry Run
3. Nested Loops (outer for rows, inner for columns)
4. Conditions (when to print and when not)
5. Print control: `end=""` in Python, `cout` in C++
```

---

## 🧩 **Categories of Pattern Problems**

| Type                         | Examples                             |
| ---------------------------- | ------------------------------------ |
| Square / Rectangle           | Solid, Hollow, Number square         |
| Triangle (Right/Equilateral) | Increasing, Decreasing, Number       |
| Pyramid                      | Full pyramid, Hollow pyramid         |
| Diamond                      | Solid, Hollow diamond                |
| Numeric/Character            | Floyd, Pascal, Alphabets             |
| Advanced                     | Butterfly, Zigzag, Spiral, Hourglass |

---

# ✨ Part 1: **Basic Square / Rectangle Patterns**

---

### 🔹 Pattern 1: Solid Square

```
n = 4
* * * *
* * * *
* * * *
* * * *
```

#### ✅ Python Code:

```python
n = 4
for i in range(n):
    for j in range(n):
        print("*", end=" ")
    print()
```

#### ✅ C++ Code:

```cpp
int n = 4;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        cout << "* ";
    }
    cout << endl;
}
```

---

### 🔹 Pattern 2: Hollow Square

```
n = 4
* * * *
*     *
*     *
* * * *
```

#### ✅ Python Code:

```python
n = 4
for i in range(n):
    for j in range(n):
        if i == 0 or i == n-1 or j == 0 or j == n-1:
            print("*", end=" ")
        else:
            print(" ", end=" ")
    print()
```

#### ✅ C++ Code:

```cpp
int n = 4;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        if(i == 0 || i == n-1 || j == 0 || j == n-1)
            cout << "* ";
        else
            cout << "  ";
    }
    cout << endl;
}
```

---

## 🔺 Part 2: **Right Angle Triangle Patterns**

---

### 🔹 Pattern 3: Left-Aligned Triangle

```
n = 4
*  
* *  
* * *  
* * * *
```

#### ✅ Python Code:

```python
n = 4
for i in range(1, n+1):
    print("* " * i)
```

#### ✅ C++ Code:

```cpp
int n = 4;
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << endl;
}
```

---

### 🔹 Pattern 4: Right-Aligned Triangle

```
n = 4
      *  
    * *  
  * * *  
* * * *
```

#### ✅ Python Code:

```python
n = 4
for i in range(1, n+1):
    print("  " * (n-i) + "* " * i)
```

#### ✅ C++ Code:

```cpp
int n = 4;
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n-i; j++)
        cout << "  ";
    for(int j = 1; j <= i; j++)
        cout << "* ";
    cout << endl;
}
```

---

### 🔹 Pattern 5: Inverted Triangle

```
n = 4
* * * *  
* * *  
* *  
*
```

#### ✅ Python Code:

```python
n = 4
for i in range(n, 0, -1):
    print("* " * i)
```

#### ✅ C++ Code:

```cpp
int n = 4;
for(int i = n; i >= 1; i--) {
    for(int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << endl;
}
```

---

## 🔻 Part 3: **Pyramid Patterns**

---

### 🔹 Pattern 6: Full Pyramid

```
n = 4
      *  
    * * *  
  * * * * *  
* * * * * * *
```

#### ✅ Python Code:

```python
n = 4
for i in range(n):
    print("  " * (n - i - 1) + "* " * (2*i + 1))
```

#### ✅ C++ Code:

```cpp
int n = 4;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n-i-1; j++)
        cout << "  ";
    for(int j = 0; j < 2*i+1; j++)
        cout << "* ";
    cout << endl;
}
```

---

### 🔹 Pattern 7: Hollow Pyramid

```
n = 4
      *  
    *   *  
  *       *  
* * * * * * *
```

#### ✅ Python Code:

```python
n = 4
for i in range(n):
    print("  " * (n - i - 1), end="")
    for j in range(2 * i + 1):
        if j == 0 or j == 2 * i or i == n - 1:
            print("*", end=" ")
        else:
            print(" ", end=" ")
    print()
```

---


## 💎 Part 4: **Diamond Patterns**

---

### 🔹 Pattern 8: Solid Diamond

```
n = 4
      *  
    * * *  
  * * * * *  
* * * * * * *  
  * * * * *  
    * * *  
      *
```

#### ✅ Python Code:

```python
n = 4
# Upper half
for i in range(n):
    print("  " * (n - i - 1) + "* " * (2 * i + 1))

# Lower half
for i in range(n - 2, -1, -1):
    print("  " * (n - i - 1) + "* " * (2 * i + 1))
```

---

### 🔹 Pattern 9: Hollow Diamond

```
n = 4
      *  
    *   *  
  *       *  
*           *  
  *       *  
    *   *  
      *
```

#### ✅ Python Code:

```python
n = 4
# Upper half
for i in range(n):
    print("  " * (n - i - 1), end="")
    for j in range(2 * i + 1):
        if j == 0 or j == 2 * i:
            print("*", end=" ")
        else:
            print(" ", end=" ")
    print()

# Lower half
for i in range(n - 2, -1, -1):
    print("  " * (n - i - 1), end="")
    for j in range(2 * i + 1):
        if j == 0 or j == 2 * i:
            print("*", end=" ")
        else:
            print(" ", end=" ")
    print()
```

---

## 🔢 Part 5: **Number Patterns**

---

### 🔹 Pattern 10: Floyd’s Triangle

```
n = 5
1  
2 3  
4 5 6  
7 8 9 10  
11 12 13 14 15
```

#### ✅ Python Code:

```python
n = 5
num = 1
for i in range(1, n+1):
    for j in range(i):
        print(num, end=" ")
        num += 1
    print()
```

---

### 🔹 Pattern 11: Triangle with Row Numbers

```
n = 4
1  
2 2  
3 3 3  
4 4 4 4
```

#### ✅ Python Code:

```python
n = 4
for i in range(1, n+1):
    print((str(i) + " ") * i)
```

---

### 🔹 Pattern 12: Triangle with Increasing Numbers

```
n = 4
1  
1 2  
1 2 3  
1 2 3 4
```

#### ✅ Python Code:

```python
n = 4
for i in range(1, n+1):
    for j in range(1, i+1):
        print(j, end=" ")
    print()
```

---

## 🔤 Part 6: **Alphabet Patterns**

---

### 🔹 Pattern 13: Triangle with Same Alphabet per Row

```
n = 4
A  
B B  
C C C  
D D D D
```

#### ✅ Python Code:

```python
n = 4
for i in range(n):
    ch = chr(ord('A') + i)
    print((ch + " ") * (i + 1))
```

---

### 🔹 Pattern 14: Triangle with Increasing Alphabets

```
n = 4
A  
A B  
A B C  
A B C D
```

#### ✅ Python Code:

```python
n = 4
for i in range(n):
    for j in range(i + 1):
        print(chr(ord('A') + j), end=" ")
    print()
```

---

## 🦋 Part 7: **Creative Patterns**

---

### 🔹 Pattern 15: Butterfly Pattern

```
n = 4
*       *
* *     * *
* * *   * * *
* * * * * * *
* * * * * * *
* * *   * * *
* *     * *
*       *
```

#### ✅ Python Code:

```python
n = 4
# Upper Half
for i in range(1, n+1):
    print("* " * i + "  " * (n - i) * 2 + "* " * i)

# Lower Half
for i in range(n, 0, -1):
    print("* " * i + "  " * (n - i) * 2 + "* " * i)
```

---

### 🔹 Pattern 16: Pascal’s Triangle

```
n = 5
        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1
```

#### ✅ Python Code:

```python
from math import comb

n = 5
for i in range(n):
    print("  " * (n - i - 1), end="")
    for j in range(i + 1):
        print(comb(i, j), end="   ")
    print()
```

---

## Conclusion: What You Should Practice

| Pattern Type | Try These                    |
| ------------ | ---------------------------- |
| Square       | Solid, Hollow                |
| Triangle     | Left, Right, Inverted        |
| Pyramid      | Solid, Hollow                |
| Diamond      | Solid, Hollow                |
| Numeric      | Floyd, Pascal, Incremental   |
| Alphabet     | Row same, incremental        |
| Advanced     | Butterfly, Hourglass, Zigzag |

---
