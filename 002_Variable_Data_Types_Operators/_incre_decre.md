

### 📘 **Note on Post-Increment (`a++`) vs Pre-Increment (`++a`)**

#### ✅ Example:

```cpp
int a = 5;
int b = a++;  // Post-increment
```

* `a++` → Use the value of `a` first, then increment it.
* So, `b = 5`, then `a = 6`

🔹 **Final values:**

```
a = 6  
b = 5
```

---

```cpp
int a = 5;
int b = ++a;  // Pre-increment
```

* `++a` → Increment `a` first, then use the new value.
* So, `a = 6`, then `b = 6`

🔹 **Final values:**

```
a = 6  
b = 6
```

---

### 📌 Summary Table:

| Expression | `a` Final Value | `b` Value |
| ---------- | --------------- | --------- |
| `b = a++`  | 6               | 5         |
| `b = ++a`  | 6               | 6         |

---
