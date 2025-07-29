
# 📌 **Functions in Python (Detailed Notes)**

---

## ✅ **1. What is a Function?**

A **function** is a block of reusable code that performs a specific task when called.

### 👉 Purpose:

* Avoids repeating code.
* Makes programs organized and easier to manage.
* Helps in breaking programs into smaller parts (Modular programming).

---

## ✅ **2. Types of Functions in Python:**

| Type                       | Description                                                       |
| -------------------------- | ----------------------------------------------------------------- |
| **Built-in Functions**     | Already provided by Python. Example: `print()`, `len()`, `sum()`. |
| **User-defined Functions** | Functions created by the user using `def` keyword.                |

---

## ✅ **3. Defining a Function (User-defined)**

Syntax:

```python
def function_name(parameters):
    """docstring (optional)"""
    # function body
    return value  # (optional)
```

---

## ✅ **4. Function Components:**

| Part            | Meaning                                                |
| --------------- | ------------------------------------------------------ |
| `def`           | Keyword to define function.                            |
| `function_name` | Function’s name (follows naming rules like variables). |
| `parameters`    | Input values (optional).                               |
| `docstring`     | Optional string to describe function purpose.          |
| `function body` | Set of statements (what the function does).            |
| `return`        | Sends result back to caller (optional).                |

---

## ✅ **5. Function Example:**

```python
def greet(name):
    """This function greets the person"""
    print("Hello,", name)
```

---

## ✅ **6. Calling a Function:**

You must **call** a function to execute it.

```python
greet("Shreya")
```

---

## ✅ 7. Parameters vs Arguments

| Term          | Meaning                                                               |
| ------------- | --------------------------------------------------------------------- |
| **Parameter** | Variable name in the **function definition** (placeholder for input). |
| **Argument**  | Actual **value you pass** into the function when you call it.         |

**Flow:** Arguments are supplied → copied/assigned into parameters → function runs with those values.



### Python Example

```python
def add(a, b):          # a, b = parameters
    return a + b

print(add(5, 3))        # 5, 3 = arguments
# Output: 8
```


### C++ Example

```cpp
#include <iostream>
using namespace std;

int add(int a, int b) { // a, b = parameters (pass by value: copies)
    return a + b;
}

int main() {
    cout << add(5, 3) << endl; // 5, 3 = arguments
    return 0;
}
```

**Note:** In C++, parameters like `int a` receive a **copy** of each argument. Use references (`int& a`) to modify the caller’s variable.


**Memory Picture (mental model):**
Parameters = empty labeled boxes; Arguments = values you put into those boxes when calling the function.

---

## ✅ **8. Return Statement:**

* Ends function and optionally returns a result.

```python
def square(num):
    return num * num

print(square(4))  # Output: 16
```

---

## ✅ **9. Types of Arguments:**

| Type                          | Description                                            |
| ----------------------------- | ------------------------------------------------------ |
| **Positional Arguments**      | Arguments passed in correct order.                     |
| **Keyword Arguments**         | Arguments with key=value pairs.                        |
| **Default Arguments**         | Predefined argument values.                            |
| **Variable-length Arguments** | Allows multiple arguments using `*args` or `**kwargs`. |

### ▶️ Positional & Keyword Example:

```python
def info(name, age):
    print(name, "is", age, "years old.")

info("Shreya", 22)               # Positional
info(age=22, name="Shreya")      # Keyword
```

### ▶️ Default Arguments:

```python
def greet(name="Guest"):
    print("Hello,", name)

greet()              # Output: Hello, Guest
greet("Shreya")      # Output: Hello, Shreya
```

### ▶️ Variable-length Arguments:

```python
def sum_all(*numbers):   # *args → tuple
    total = 0
    for num in numbers:
        total += num
    return total

print(sum_all(1, 2, 3, 4))  # Output: 10
```

---

## ✅ **10. Docstring (Documentation String):**

Used to describe what the function does.

```python
def square(num):
    """Returns square of a number"""
    return num * num

print(square.__doc__)
```

---

## ✅ **11. Lambda Functions (Anonymous Functions):**

Short functions using `lambda` keyword.

```python
square = lambda x: x * x
print(square(5))   # Output: 25
```

---

## ✅ **12. Nested Functions (Functions inside Functions):**

```python
def outer():
    def inner():
        print("Inside inner function")
    inner()

outer()
```

---

## ✅ **13. Recursive Functions (Function calls itself):**

```python
def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)

print(factorial(5))  # Output: 120
```

---

## ✅ **14. Difference Between `print()` and `return`:**

| Feature   | `print()`                              | `return`                       |
| --------- | -------------------------------------- | ------------------------------ |
| Purpose   | Displays output on screen.             | Sends output to caller.        |
| Usability | Only shows result, cannot use further. | Can be stored or reused later. |

---

## ✅ **15. Best Practices for Functions:**

* Use descriptive names.
* Keep function small (single task).
* Use docstrings for clarity.
* Avoid using too many global variables.
* Use `return` wherever needed.

---

## ✅ **16. Summary Table:**

| Feature       | Explanation                                      |
| ------------- | ------------------------------------------------ |
| Function      | Block of reusable code.                          |
| Define        | Using `def` keyword.                             |
| Call          | Using function\_name().                          |
| Arguments     | Input values to function.                        |
| Return        | Output from function.                            |
| Types         | Built-in, User-defined.                          |
| Special Forms | Lambda, Recursive, Nested, Variable-length args. |

---

## ✅ **17. Simple Example for Quick Revision:**

```python
def multiply(x, y=2):
    """Multiply 2 numbers (default y=2)"""
    return x * y

print(multiply(3))      # Output: 6 (3*2)
print(multiply(3, 4))   # Output: 12 (3*4)
```

---