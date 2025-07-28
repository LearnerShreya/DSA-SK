
# **Functions in Memory**

---

## 1. What Is a Function?

A **function** is a named, reusable block of code that performs a specific task. It:

* Can take **inputs** (parameters)
* Processes those inputs
* May **return** an output

```cpp
int add(int a, int b) {
    return a + b;
}
```

Calling `add(3, 5)` returns `8`.

---

## 2. Memory Layout of a C++ Program

When a C++ program runs, its memory is divided into several sections:

| Segment            | Description                                                                |
| ------------------ | -------------------------------------------------------------------------- |
| Code Segment       | Stores compiled machine instructions (function bodies, logic)              |
| Stack              | Stores function calls, parameters, local variables (LIFO structure)        |
| Heap               | For dynamic memory allocation using `new`, `malloc`, etc.                  |
| Global/Static Area | For global and static variables                                            |
| CPU Registers      | Temporary high-speed storage (used for return values, loop counters, etc.) |

In this explanation, we will focus mainly on the **stack**.

---

## 3. What Happens When a Function Is Called?

Consider this code:

```cpp
int square(int n) {
    int result = n * n;
    return result;
}

int main() {
    int x = 5;
    int output = square(x);
}
```

Let's walk through the memory and stack behavior step by step.

---

## 4. Stack Memory Flow – Step-by-Step Execution

### Step 1: Execution Starts in `main()`

A stack frame for `main()` is created.

```
| output (uninitialized) |
| x = 5                  |   ← Local variable in main()
```

---

### Step 2: `square(x)` is Called

* `x` is passed **by value** (copied into `n`)
* A new **stack frame** for `square()` is created

```
| result = 25           |   ← Local variable in square()
| n = 5                 |   ← Parameter
| return address        |   ← Where to return in main()
-------------------------
| output (uninitialized)|
| x = 5                 |
```

---

### Step 3: Return to `main()`

* Value `25` is returned
* `square()` stack frame is removed (popped)
* Returned value assigned to `output`

```
| output = 25 |
| x = 5       |
```

---

## 5. What’s in a Stack Frame?

Each function call gets its own **stack frame**. It includes:

| Component         | Description                                       |
| ----------------- | ------------------------------------------------- |
| Parameters        | Inputs passed to the function (copied by value)   |
| Local Variables   | Created inside the function                       |
| Return Address    | Tells CPU where to return after the function ends |
| Return Value Slot | (Optional) space to store return value            |

A new stack frame is **pushed** for every function call and **popped** when the function ends.

---

## 6. Recursion and Stack Growth

A recursive function calls itself, creating new stack frames each time.

```cpp
int fact(int n) {
    if (n == 1) return 1;
    return n * fact(n - 1);
}
```

Calling `fact(4)`:

```
| n = 1 | → returns 1
---------
| n = 2 | → returns 2 * 1 = 2
---------
| n = 3 | → returns 3 * 2 = 6
---------
| n = 4 | → returns 4 * 6 = 24
---------
```

Each recursive call has its **own local memory**. Too many recursive calls may cause **stack overflow**.

---

## 7. Pass by Value vs Pass by Reference

### Pass by Value (default for basic types)

* A **copy** of the variable is passed
* Original variable remains unchanged

```cpp
void update(int a) {
    a = 10;
}

int x = 5;
update(x);  // x remains 5
```

---

### Pass by Reference (`&`)

* The actual variable is passed
* Changes affect the original variable

```cpp
void update(int &a) {
    a = 10;
}

int x = 5;
update(x);  // x becomes 10
```

---

## 8. Stack Frame Diagram

Before function call:

```
| output (uninitialized) |
| x = 5                  |
```

During function execution:

```
| result = 25            |
| n = 5                  |
| return address         |
--------------------------
| output (uninitialized) |
| x = 5                  |
```

After return:

```
| output = 25 |
| x = 5       |
```

---

## 9. What is the Return Address?

Every function call stores a **return address** in its stack frame.

* It’s the instruction location in the calling function (e.g., `main()`)
* When the called function finishes, control jumps back to this address

---

## 10. When Does Memory Get Freed?

| Memory Item             | Allocated When             | Freed When                         |
| ----------------------- | -------------------------- | ---------------------------------- |
| Parameters              | Function is called (stack) | Function ends                      |
| Local Variables         | Function is called (stack) | Function ends                      |
| Return Address          | Function is called (stack) | Function ends                      |
| Heap Variables          | `new` / `malloc` is called | Only if manually `delete` / `free` |
| Global/Static Variables | Program starts             | Program ends                       |

---

## 11. Advanced Note: Where Is the Return Value Stored?

This depends on the system architecture and compiler (calling convention):

* **Basic types** (int, float) → returned in CPU registers (e.g., `eax` on x86)
* **Large structures or objects** → returned via memory (using hidden pointer)

After return, the value is assigned to a variable in the caller.

---

## 12. Execution Flow Summary

```
main() starts
↓
Local variables in main() are created
↓
Function call: square(x)
↓
New stack frame for square()
↓
square() executes and returns value
↓
Stack frame is popped
↓
main() uses returned value
↓
Program ends
```

---

## 13. Complete Concept Summary Table

| Concept            | Stored In        | Lifetime                   |
| ------------------ | ---------------- | -------------------------- |
| Function Code      | Code Segment     | Entire program duration    |
| Parameters         | Stack            | While function is running  |
| Local Variables    | Stack            | While function is running  |
| Return Address     | Stack            | Until function returns     |
| Return Value       | Register / Stack | Until it is assigned       |
| Global/Static Vars | Global Area      | Entire program duration    |
| Heap Memory        | Heap             | Until manually deallocated |

---

## 14. Best Practices for Beginners

* Always initialize local variables
* Do not return the address of local variables (dangling pointer)
* Ensure base cases in recursion to prevent stack overflow
* Use pass-by-reference only when modification is needed
* Understand stack vs heap allocation clearly

---

## 15. Final Wrap-Up

* Every function call creates a **new stack frame**
* Each stack frame stores parameters, locals, return info
* Stack memory is automatically freed after function returns
* Stack grows and shrinks dynamically as functions are called/returned
* This model applies to most stack-based compiled languages (C, C++, Rust, etc.)

---