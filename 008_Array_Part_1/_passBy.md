# ✅ What is a Primitive Data Type?

## 🔹 Definition:

A **Primitive Data Type** is a **basic built-in data type** provided by a programming language. It:

* Stores **raw data values** directly in memory.
* Is **not a class or object**.
* Is usually **immutable**.
* Requires **very little memory** and is **fast** to access.

---

## 🔹 Examples:

| Language | Primitive Types                                                                   |
| -------- | --------------------------------------------------------------------------------- |
| C++      | `int`, `float`, `char`, `bool`, `double`, etc.                                    |
| Python   | `int`, `float`, `bool`, `str` (treated like primitive, but is actually an object) |

> In Python, even primitive-looking values are actually **objects**. But they behave like primitives due to their simplicity and immutability.

---

# ✅ When You Pass a Primitive Type (C++ vs Python)

---

## 🔹 C++: **Passed by Value by Default**

### 🔸 What happens?

When you pass a **primitive variable** to a function:

* A **copy** of that value is passed.
* Any modification inside the function does **not affect** the original.

### 🔸 Example:

```cpp
void changeValue(int x) {
    x = 100;
}

int main() {
    int a = 10;
    changeValue(a);
    cout << a;  // Output: 10, NOT 100
}
```

✅ **Because `x` is just a copy of `a`**.

---

### 🔸 To modify original: **Pass by Reference**

```cpp
void changeValue(int &x) {
    x = 100;
}

int main() {
    int a = 10;
    changeValue(a);
    cout << a;  // Output: 100 ✅
}
```

---

## 🔹 Python: **Pass-by-Object-Reference (Immutable = value-like)**

When you pass an `int`, `float`, or `str` to a function:

* You pass the **reference** (memory address),
* But since it is **immutable**, the value behaves like it's **passed by value**.
* You **cannot modify it** inside the function.

### 🔸 Example:

```python
def changeValue(x):
    x = 100

a = 10
changeValue(a)
print(a)  # Output: 10 ✅
```

✅ Even though reference is passed, `int` is immutable, so a new `x` is created.

---

## 🔹 Summary Table: What Happens When You Pass a Primitive Type?

| Language | Pass Type            | Change Affects Original?   | Why?                         |
| -------- | -------------------- | -------------------------- | ---------------------------- |
| C++      | Pass by value (copy) | ❌                          | Copy of variable             |
| C++      | Pass by reference    | ✅                          | Passed actual memory address |
| Python   | Object reference     | ❌ (for immutables)         | New object created           |
| Python   | Object reference     | ✅ (for mutables like list) | Same object is modified      |

---

# ✅ Relation of Primitive Type to Default Parameters

## 🔹 C++:

You can use a **primitive** as a **default value** for function parameters.

```cpp
void greet(string name = "Shreya") {
    cout << "Hello, " << name << "!\n";
}
```

> ✅ Works with any primitive — `int`, `float`, `char`, etc.

---

## 🔹 Python:

Same in Python:

```python
def greet(name="Shreya"):
    print(f"Hello, {name}!")
```

> ✅ Safe to use primitives as default — because they are **immutable** and don’t change across calls.

⚠️ Mutable types like `list`, `dict` can cause bugs in Python defaults.

---

# ✅ Relation to Memory

| Feature         | Primitive Type                  | Explanation                            |
| --------------- | ------------------------------- | -------------------------------------- |
| Memory Location | Stored on the stack (C++)       | Direct, fast access                    |
| Size            | Fixed (e.g., 4 bytes for `int`) | Efficient                              |
| Immutable       | Usually immutable               | Safe, prevents accidental modification |

---

# ✅ Summary (You Should Remember):

* **Primitive = simplest data type**, like `int`, `float`, `bool`.
* In **C++**, primitives are **passed by value** (copied), unless `&` (reference) is used.
* In **Python**, primitives are **immutable**, so even though passed by reference, they **behave like value**.
* You can safely use primitives as **default function parameters** in both C++ and Python.
* Their behavior is **predictable, safe, and fast**, making them ideal for basic operations and logic.

---