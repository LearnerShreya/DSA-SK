<h1> <code>if __name__ == "__main__"</code> in Python </h1>

---

## ✅ Meaning:

```python
if __name__ == "__main__":
```

This line simply checks:

> **"Am I running this file directly?"**

If **yes** → The code under it will run.

If **no** → The code will NOT run (usually when the file is imported elsewhere).

---

## ✅ Working:

Every Python file has a special variable called `__name__`.

| Situation                            | Value of `__name__` |
| ------------------------------------ | ------------------- |
| File is run **directly**             | `"__main__"`        |
| File is **imported** in another file | `"filename"`        |

---

<h2>With: <code>if __name__ == "__main__"</code></h2>

`greet_module.py`
```python
def greet():
    print("Hello from greet function!")

print("Top-level code running")

if __name__ == "__main__":
    print("Inside main block")
    greet()
```

### **Output (when run directly):**

```
Top-level code running
Inside main block
Hello from greet function!
```

---


<h2>Without: <code>if __name__ == "__main__"</code></h2>

`greet_module.py`
```python
def greet():
    print("Hello from greet function!")

print("Top-level code running")
print("Inside main block")
greet()
```

### **Output (when run directly):**

```
Top-level code running
Inside main block
Hello from greet function!
```
---

## ✅ So what's the difference?

> Without `if __name__ == "__main__"` → It **always runs**, even if **imported** in other files.

`import_test.py`

```python
import greet_module
```

```
Top-level code running
Inside main block
Hello from greet function!
Now inside import_test file
```

→ Everything runs during import too (which is usually unsafe).


> With it → Code under it runs **only when run directly**, NOT when imported.

`import_test.py`

```python
import greet_module
```


```
Top-level code running
```

→ Only **top-level print** runs, main block is skipped.

---


### ✅ Conclusion:

| Case                               | Output on Import |
| ---------------------------------- | ---------------- |
| ✅ With `if __name__ == "__main__"` | Only top-level   |
| ❌ Without it                       | Everything runs  |


* ✅ **Use it for safe testing** inside modules.
* ✅ Prevents accidental running when files are imported.

---
---

## ✅ Example Setup

We have 2 files:

1. **`greet_module.py`** → Contains the function & main block.
2. **`import_test.py`** → This file imports `greet_module`.

---

<h2>Case 1: With <code>if __name__ == "__main__"</code></h2>

#### **File 1: greet\_module.py**

```python
def greet():
    print("Hello from greet function!")

print("Top-level code running in greet_module")

if __name__ == "__main__":
    print("Inside main block of greet_module")
    greet()
```

#### **File 2: import\_test.py**

```python
import greet_module

print("Now inside import_test file")
```

#### ✅ Output (When you run `import_test.py`):

```
Top-level code running in greet_module
Now inside import_test file
```

> ✅ Only **top-level code** runs automatically from `greet_module`.
> ✅ `if __name__ == "__main__"` block DOES NOT RUN when imported.

---

### ✅ ✅ How to Run the Main Block *After Importing* (By Hand):

Add a function for the main block:

#### **Modify greet\_module.py** (Add main() function):

```python
def greet():
    print("Hello from greet function!")

def main():  # Main block converted to function
    print("Inside main block of greet_module")
    greet()

print("Top-level code running in greet_module")

if __name__ == "__main__":
    main()
```

#### Now in import\_test.py:

```python
import greet_module

print("Now inside import_test file")

# Manually calling main block
print("Calling main block manually after import:")
greet_module.main()
```

#### ✅ Output:

```
Top-level code running in greet_module
Now inside import_test file
Calling main block manually after import:
Inside main block of greet_module
Hello from greet function!
```

---

### ✅ ✅ Key Trick:

* ✅ Put your **main block code inside a function (like `main()`)**.
* ✅ Now, you can easily **import & run** it anytime!

---

### ✅ Diagram:

```plaintext
import_test.py
     ↓
Import greet_module → Only Top-Level Runs
     ↓
Manually call greet_module.main() → Runs Main Block
```

---

<h2>Case 2: Without <code>if __name__ == "__main__"</code></h2>

Already explained above (unsafe, runs everything on import).

---

### ✅ Summary Table:

| Case                                        | Runs on Import? | Can Run Main Manually?      |
| ------------------------------------------- | --------------- | --------------------------- |
| ✅ With `if __name__ == "__main__"` + main() | Only top-level  | ✅ Yes (via `module.main()`) |
| ❌ Without `if __name__ == "__main__"`       | Everything runs | ❌ No clean control          |

---

### ✅ Best Practice:

> Always use:

```python
if __name__ == "__main__":
    main()
```

It gives:

* **Safety on import**
* Ability to **call main manually** if needed.

---

