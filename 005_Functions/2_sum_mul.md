

### ✅ Code:

```python
def sum(a, b):
    return a + b

def mul(c, d):
    return c * d

o = int(input("Enter num 'o': "))
p = int(input("Enter num 'p': "))
print(sum(o, p))
print(mul(o, p))

if __name__ == "__main__":
    m = int(input("Enter num: "))
    n = int(input("Enter num: "))
    print(sum(m, n))
    print(mul(m, n))
```

---

### ✅ Super Simple Step-by-Step Working:

Let’s assume you enter:

* o = 2
* p = 3
* m = 4
* n = 5

---

### ✅ Program Flow:

1. Functions `sum()` & `mul()` are **defined** (they don't run yet).

2. Program asks:

   ```
   Enter num 'o':
   ```

   → You enter: `2`

3. Program asks:

   ```
   Enter num 'p':
   ```

   → You enter: `3`

4. It prints:

   * `sum(2, 3)` → 5
   * `mul(2, 3)` → 6

---

5. Next, Python checks:

```python
if __name__ == "__main__"
```

✅ This runs because you are running the file directly.

6. It asks:

   ```
   Enter num:
   ```

   → You enter: `4`

7. It asks:

   ```
   Enter num:
   ```

   → You enter: `5`

8. It prints:

   * `sum(4, 5)` → 9
   * `mul(4, 5)` → 20

---

### ✅ Full Dry Run Table (with Example Inputs):

| Step | Action                              | Output / Effect |
| ---- | ----------------------------------- | --------------- |
| 1    | Define `sum()` and `mul()`          | Functions ready |
| 2    | Ask for `o`                         | You input `2`   |
| 3    | Ask for `p`                         | You input `3`   |
| 4    | Run `sum(o, p)` → sum(2, 3)         | Prints `5`      |
| 5    | Run `mul(o, p)` → mul(2, 3)         | Prints `6`      |
| 6    | Check if file is run directly → YES | Continue        |
| 7    | Ask for `m`                         | You input `4`   |
| 8    | Ask for `n`                         | You input `5`   |
| 9    | Run `sum(m, n)` → sum(4, 5)         | Prints `9`      |
| 10   | Run `mul(m, n)` → mul(4, 5)         | Prints `20`     |

---

### ✅ Easy Explanation:

* The code before `if __name__ == "__main__"` → **always runs**.
* Code inside `if __name__ == "__main__"` → **runs only if you directly run the file** (not during import).
* Functions don’t care about variable names (`o, p, m, n`) — they just take numbers you pass to them.

---

### ✅ One-Line Summary:

> First, you input `o, p` → sum & multiply → Then, you input `m, n` (in main block) → sum & multiply again.

---
