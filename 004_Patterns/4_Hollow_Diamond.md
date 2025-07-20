

# 📘 **Pattern Printing – Hollow Diamond Shape (using Python)**

---

## 🔸 Objective

When the user inputs `n = 4`, the pattern printed is:

```
      * 
    *   * 
  *       * 
*           * 
  *       *     
    *   *
      *
```

This is a **hollow diamond pattern** built using:

* Spaces to align stars symmetrically.
* Asterisks (`*`) only at the **edges** of each line.

---

## 🔹 Full Code

```python
def print_hollow_line(spaces, stars):
    print("  " * spaces, end="")  # print leading spaces
    for j in range(stars):
        if j == 0 or j == stars - 1:  # print * at first or last position
            print("* ", end="")
        else:
            print("  ", end="")      # print double space for hollow part
    print()  # move to next line

n = int(input("Enter n: "))

# Upper half of diamond
for i in range(n):
    print_hollow_line(n - i - 1, 2 * i + 1)

# Lower half of diamond
for i in range(n - 2, -1, -1):
    print_hollow_line(n - i - 1, 2 * i + 1)
```

---

## 🔍 **Understanding Each Part**

---

### 🔸 1. Function: `print_hollow_line(spaces, stars)`

This function does 3 things:

1. Prints `spaces` number of `"  "` (double space) to shift the pattern to the right.
2. Loops `stars` times:

   * If `j == 0` or `j == stars - 1`: print `"* "`
   * Else: print `"  "` (double space for hollow inside)
3. `print()` moves cursor to the next line.

---

### 🔸 2. `n = int(input(...))`

This takes user input to define the **height** of the upper triangle.
For `n = 4`, there are:

* 4 lines in the upper half
* 3 lines in the lower half

---

### 🔸 3. Upper Half Loop

```python
for i in range(n):
    print_hollow_line(n - i - 1, 2 * i + 1)
```

| `i` | spaces = `n-i-1` | stars = `2*i+1` |
| --- | ---------------- | --------------- |
| 0   | 3                | 1               |
| 1   | 2                | 3               |
| 2   | 1                | 5               |
| 3   | 0                | 7               |

---

### 🔸 4. Lower Half Loop

```python
for i in range(n-2, -1, -1):
    print_hollow_line(n - i - 1, 2 * i + 1)
```

Goes **in reverse**, skipping the middle line.

| `i` | spaces | stars |
| --- | ------ | ----- |
| 2   | 1      | 5     |
| 1   | 2      | 3     |
| 0   | 3      | 1     |

---

## 🧠 Python Tutor–Style Frames (step-by-step memory)

---

### 🔹 **Global Frame**

| Variable            | Value              |
| ------------------- | ------------------ |
| `n`                 | 4                  |
| `i`                 | Changes in loops   |
| `print_hollow_line` | Function reference |

---

### 🔹 **Function Call: `print_hollow_line(3, 1)`**

**Loop: `j = 0` to `0`**

* Leading spaces: `"  "` × 3 → prints 6 spaces
* Only one star at `j = 0`

**Output:**

```
      * 
```

---

### 🔹 **Function Call: `print_hollow_line(2, 3)`**

**Loop: `j = 0 to 2`**

* Leading: 4 spaces
* `j = 0` → "\* "
* `j = 1` → "  "
* `j = 2` → "\* "

**Output:**

```
    *   * 
```

---

### 🔹 `print_hollow_line(1, 5)`

* Leading: 2 spaces
* Stars at j = 0 and 4

**Output:**

```
  *       * 
```

---

### 🔹 `print_hollow_line(0, 7)`

* Leading: 0
* Stars at j = 0 and 6

**Output:**

```
*           * 
```

---

## 🔁 Loop Execution Summary

### ▶️ **Upper Half**

| i | spaces | stars | Output          |
| - | ------ | ----- | --------------- |
| 0 | 3      | 1     | `      *`       |
| 1 | 2      | 3     | `    *   *`     |
| 2 | 1      | 5     | `  *       *`   |
| 3 | 0      | 7     | `*           *` |

---

### 🔁 **Lower Half (Reverse)**

| i | spaces | stars | Output        |
| - | ------ | ----- | ------------- |
| 2 | 1      | 5     | `  *       *` |
| 1 | 2      | 3     | `    *   *`   |
| 0 | 3      | 1     | `      *`     |

---

## 🎓 Final Pattern Output (n = 4)

```
      * 
    *   * 
  *       * 
*           * 
  *       *     
    *   *
      *
```

---

## 🧠 **Core Concepts Covered**

| Concept               | Explanation                                                          |
| --------------------- | -------------------------------------------------------------------- |
| Function              | Reusable logic for printing hollow lines                             |
| Loop (for)            | To print upper and lower halves symmetrically                        |
| Conditional (if)      | To print `*` only at the ends (`j == 0 or j == stars - 1`)           |
| String Multiplication | `"  " * spaces` gives precise leading spaces for centering the stars |
| Symmetry              | Using the same function for both upper and lower parts               |

---

## 💡 Tips:

* Focus on how **spaces** control indentation and alignment.
* Learn how the `if` condition inside the loop **creates hollowness**.
* Try with other values of `n` (like 2, 5, 6) to see how the pattern grows.

---