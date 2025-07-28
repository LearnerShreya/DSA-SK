

# **Functions in C++ – Quick Revision Notes**

---

## ✅ 1. **Function Definition** (Main Part)

Where we write the **actual working code** (logic) of the function.

### 🔹 Syntax:

```cpp
return_type function_name(parameters) {
    // Code (statements)
    return value;  // optional
}
```

> `void` → No value returned.

---

## ✅ 2. **Function Declaration** (Prototype)

Tells the compiler about the function **before use** (needed if function is below `main()`).

### 🔹 Syntax:

```cpp
return_type function_name(parameters);
```

---

## ✅ 3. **Function Calling**

Executes (runs) the function.

### 🔹 Syntax:

```cpp
function_name(arguments);
```

---

## ✅ 4. **Example:**

```cpp
#include <iostream>
using namespace std;

void greet();  // Declaration (Prototype)

void greet() {  // Definition
    cout << "Hello, Welcome!" << endl;
}

int main() {
    greet();  // Calling
    return 0;
}
```

---



## ✅ 5. **Note on `void` Return Type (With Example):**

When we use `void` as the return type:

* Function **does not return any value**.
* Output or task happens **inside the function** itself.
* No need to use `cout` in `main()` during function calling.

### 🔹 Example:

```cpp
#include <iostream>
using namespace std;

void showMessage() {  // Definition (void type)
    cout << "This is a message from inside the function!" << endl;
}

int main() {
    showMessage();  // Calling (No cout needed here)
    return 0;
}
```

> ✅ Output happens inside `showMessage()`. No `cout` in `main()` needed.


---

## ✅ Why Declaration + Definition Separately?

| Reason                             | Benefit                                     |
| ---------------------------------- | ------------------------------------------- |
| Declaration informs compiler early | Allows calling function before it's defined |
| Better code organization           | Declaration at top, definition below main() |

---

## ✅ Quick Trick:

✨ If function is **above `main()`** → **No declaration needed**.
✨ If function is **below `main()`** → Declaration (Prototype) is required.

---

## ✅ Quick Summary Table:

| Concept              | Meaning                                                     |
| -------------------- | ----------------------------------------------------------- |
| Function Definition  | Code block where the actual task is written.                |
| Function Declaration | Tells compiler about function before its use.               |
| Function Calling     | Executes function to perform the task.                      |
| `void` Return Type   | Performs task but returns no value. Output inside function. |

---

## ✅ **Types of Functions in C++** (Based on Arguments & Return):

| Type                        | Meaning                                               |
| --------------------------- | ----------------------------------------------------- |
| No Arguments, No Return     | Does a task, no data taken or returned.               |
| With Arguments, No Return   | Takes data (arguments), but does not return anything. |
| No Arguments, With Return   | No data taken but returns a value.                    |
| With Arguments, With Return | Takes data and returns result.                        |

### 🔹 Example (All Types Together):

```cpp
void show();             // No arguments, No return
void display(int x);     // With arguments, No return
int getNumber();         // No arguments, With return
int sum(int a, int b);   // With arguments, With return
```

---

## ✅ **C++ vs Python Function Comparison:**

| Feature             | C++                                 | Python                       |
| ------------------- | ----------------------------------- | ---------------------------- |
| Syntax (Definition) | `return_type function_name(params)` | `def function_name(params):` |
| Return Type Needed? | Yes (e.g., `int`, `void`)           | No need to specify           |
| Semicolons Required | Yes (`;` at declaration & calling)  | No semicolons                |
| Indentation         | Not strict (uses `{}`)              | Strict indentation           |
| Function Prototype? | Required if defined after `main()`  | Not required                 |
| Main Function?      | Required (`int main()`)             | Not always needed            |

---
