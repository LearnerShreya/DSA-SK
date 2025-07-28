
# Functions in Memory – Python Version (Compared to C++)

---

## 1. Key Differences Between Python and C++ (Memory Perspective)

| Aspect              | C++ (Compiled)                            | Python (Interpreted)                            |
| ------------------- | ----------------------------------------- | ----------------------------------------------- |
| Memory Model        | Static + Manual                           | Dynamic + Managed by Garbage Collector          |
| Function Call Stack | Explicit native call stack (stack frames) | Uses Python Virtual Machine (PVM) call stack    |
| Memory Allocation   | Manual (stack, heap)                      | Automatic, via references and garbage collector |
| Variables           | Stores actual values                      | Stores **references to objects**                |
| Performance         | Very fast, direct memory control          | Slower, due to abstraction and safety           |

---

## 2. Python Function Execution Flow

Let’s take a simple Python example:

```python
def square(n):
    result = n * n
    return result

x = 5
output = square(x)
```

This looks similar to C++, but what happens internally is different.

---

## 3. Python Stack Frame Flow – Step-by-Step

### Step 1: Script Starts

Python interpreter runs line-by-line in the **main frame** (also called `__main__` scope):

```
Global Frame:
x = 5
```

---

### Step 2: `square(x)` is Called

* A new **function frame** is pushed onto the Python **call stack**
* `n` is a **reference** to the object `5`
* `result` becomes a reference to object `25`

```
Call Stack:
-------------
square() frame:
n → 5
result → 25
return address → main
-------------
Global frame:
x → 5
output → ?
```

---

### Step 3: Return to Main

* `25` is returned
* The function frame is removed (popped)
* Returned value is assigned to `output`

```
Global frame:
x → 5
output → 25
```

---

## 4. Stack Frame in Python

Each function call creates a **frame object** that includes:

| Part            | Description                               |
| --------------- | ----------------------------------------- |
| Local Namespace | Function's local variables                |
| Arguments       | Parameters (references to passed objects) |
| Return Address  | Where to resume execution                 |
| Reference Count | Used by garbage collector                 |

---

## 5. Pass by Object Reference (aka “Pass by Assignment”)

Python passes **references to objects**, not actual copies of memory blocks like C++ does.

### For Immutable Types (like `int`, `str`, `tuple`):

```python
def update(n):
    n = 10

x = 5
update(x)
print(x)  # Still 5
```

Here, `n` points to a copy of reference, not the same object — so original `x` is unchanged.

---

### For Mutable Types (like `list`, `dict`, `set`):

```python
def modify(lst):
    lst.append(10)

nums = [1, 2]
modify(nums)
print(nums)  # [1, 2, 10]
```

Because the **reference** to the same list is passed, changes are reflected outside.

---

## 6. Recursion in Python

Python also uses a **call stack** for recursion — just like C++. But there's a limit.

```python
def fact(n):
    if n == 1:
        return 1
    return n * fact(n - 1)

print(fact(4))  # Output: 24
```

Each recursive call pushes a new frame.

But in Python:

* **Maximum recursion depth** is limited (default: \~1000)
* You can check it using:

```python
import sys
print(sys.getrecursionlimit())
```

Too many calls → `RecursionError`.

---

## 7. Garbage Collection in Python

Unlike C++, Python doesn’t require you to manually free memory.

It uses:

* **Reference counting**
* **Cycle detection**

When an object is no longer used (reference count = 0), it's eligible for garbage collection.

---

## 8. Visual Summary: Python vs C++ Function Stack

| Feature              | C++                             | Python                           |
| -------------------- | ------------------------------- | -------------------------------- |
| Function Call Stack  | Native hardware stack           | Python Virtual Machine stack     |
| Stack Frame Contents | Parameters, locals, return addr | Locals, references, return info  |
| Value Passing        | By value / reference            | Always by object reference       |
| Memory Deallocation  | Manual (delete/free)            | Automatic via garbage collection |
| Stack Overflow       | Yes (deep recursion)            | Yes (but limited by interpreter) |

---

## 9. Final Wrap-Up for Python

* Every function call creates a new **stack frame**
* Python passes **references**, not values
* Immutable objects act like "pass by value"
* Mutable objects act like "pass by reference"
* Stack grows with each function or recursion
* Python handles memory cleanup automatically

---