# STL Tutorial One Shot

---

# **Part 4: Functions and Function Objects (Functors) in STL**

---

## **1. Function Overview**

STL algorithms often require user-defined logic — like comparing, transforming, or filtering elements.
This is where **functions, function pointers, and function objects (functors)** come into play.

---

## **2. Types of Functions Used in STL**

| Type                          | Description                            | Example                                                       |
| ----------------------------- | -------------------------------------- | ------------------------------------------------------------- |
| **Normal Function**           | Defined normally using `void` or `int` | `bool compare(int a, int b)`                                  |
| **Function Pointer**          | Passes function as argument            | `sort(v.begin(), v.end(), compare)`                           |
| **Function Object (Functor)** | Object that acts like a function       | `sort(v.begin(), v.end(), MyComparator())`                    |
| **Lambda Function**           | Anonymous inline function              | `sort(v.begin(), v.end(), [](int a, int b){ return a > b; })` |

---

## **3. Normal Function Example**

You can pass a **function** to an algorithm like `sort()` for custom sorting.

```cpp
#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a > b; // descending
}

int main() {
    vector<int> v = {4, 2, 8, 1};
    sort(v.begin(), v.end(), compare);

    for (int x : v)
        cout << x << " ";
}
```

**Output:**

```
8 4 2 1
```

---

## **4. Function Pointers**

C++ allows you to pass **function pointers** as parameters to STL algorithms.
It’s the same as passing a normal function, but using pointer syntax:

```cpp
bool cmp(int a, int b) { return a < b; }

int main() {
    vector<int> v = {10, 40, 20};
    sort(v.begin(), v.end(), cmp); // cmp is function pointer
}
```

---

## **5. Function Objects (Functors)**

### **5.1 Definition**

A **functor** is an **object that behaves like a function**.
Technically, it is a **class or struct** that **overloads the `operator()`**.

They are often used when:

* You need to maintain **state** (store information inside).
* You want to define **custom logic** inside an object.

---

### **5.2 Syntax**

```cpp
struct MyFunctor {
    bool operator()(int a, int b) {
        return a < b;
    }
};

int main() {
    vector<int> v = {5, 2, 8};
    sort(v.begin(), v.end(), MyFunctor());
}
```

**Explanation:**

* `MyFunctor()` creates an object.
* `operator()` makes it callable like a function.

---

### **5.3 Advantages of Functors**

1. Faster than function pointers (can be inlined by compiler).
2. Can store internal states (unlike plain functions).
3. Can be reused across multiple algorithms.

---

### **5.4 Example: Stateful Functor**

```cpp
struct Counter {
    int count = 0;
    void operator()(int x) {
        if (x % 2 == 0)
            count++;
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 6};
    Counter c = for_each(v.begin(), v.end(), Counter());
    cout << "Even numbers: " << c.count;
}
```

**Output:**

```
Even numbers: 3
```

Here, `for_each()` executes the functor on each element, and the state `count` is preserved.

---

## **6. Predefined Functors in STL**

STL provides many ready-to-use functors in the header `<functional>`.

| Functor            | Description             |
| ------------------ | ----------------------- |
| `plus<T>`          | Performs addition       |
| `minus<T>`         | Performs subtraction    |
| `multiplies<T>`    | Performs multiplication |
| `divides<T>`       | Performs division       |
| `modulus<T>`       | Performs modulo         |
| `greater<T>`       | Returns `a > b`         |
| `less<T>`          | Returns `a < b`         |
| `greater_equal<T>` | Returns `a >= b`        |
| `less_equal<T>`    | Returns `a <= b`        |
| `equal_to<T>`      | Returns `a == b`        |
| `not_equal_to<T>`  | Returns `a != b`        |
| `logical_and<T>`   | Logical AND             |
| `logical_or<T>`    | Logical OR              |
| `logical_not<T>`   | Logical NOT             |

---

### **6.1 Example 1: Using greater<>**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 2};
    sort(v.begin(), v.end(), greater<int>());

    for (int x : v) cout << x << " ";
}
```

**Output:**

```
4 3 2 1
```

---

### **6.2 Example 2: Using plus<> and accumulate**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4};
    int sum = accumulate(v.begin(), v.end(), 0, plus<int>());
    cout << sum;
}
```

**Output:**

```
10
```

Here, `plus<int>()` is a built-in functor that adds two numbers.

---

### **6.3 Example 3: Using logical_and<>**

```cpp
logical_and<bool> And;
cout << And(true, false); // Output: 0
cout << And(true, true);  // Output: 1
```

---

## **7. Lambda Functions**

### **7.1 Introduction**

Lambdas are **anonymous (unnamed) inline functions** introduced in C++11.

They’re extremely useful for short, custom operations inside STL algorithms.

---

### **7.2 Syntax**

```cpp
[capture](parameters) -> return_type {
    body;
};
```

**Example:**

```cpp
auto sum = [](int a, int b) {
    return a + b;
};
cout << sum(3, 5);
```

**Output:**

```
8
```

---

### **7.3 Lambda with STL Algorithm**

```cpp
vector<int> v = {1, 2, 3, 4, 5};

for_each(v.begin(), v.end(), [](int x) {
    cout << x * 2 << " ";
});
```

**Output:**

```
2 4 6 8 10
```

---

### **7.4 Lambda with Sort**

```cpp
vector<pair<int, int>> v = {{1, 5}, {2, 3}, {3, 1}};

sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b){
    return a.second < b.second;
});
```

**Output:**

```
(3,1) (2,3) (1,5)
```

---

### **7.5 Capture Clause**

The capture clause `[ ]` decides what variables from the outer scope can be used inside the lambda.

| Capture Type     | Syntax    | Meaning                              |
| ---------------- | --------- | ------------------------------------ |
| **By Value**     | `[=]`     | Makes a copy of variables            |
| **By Reference** | `[&]`     | Uses reference to original variable  |
| **Mixed**        | `[=, &x]` | All by value except `x` by reference |

**Example:**

```cpp
int a = 10, b = 20;
auto fun = [=]() { return a + b; };
cout << fun(); // 30
```

---

## **8. `std::function`**

It’s a general-purpose **function wrapper** available in `<functional>` that can store:

* Normal functions
* Lambdas
* Functors
* Function pointers

---

### **8.1 Example**

```cpp
#include <functional>
#include <iostream>
using namespace std;

void greet() { cout << "Hello"; }

int main() {
    function<void()> f = greet;
    f(); // Output: Hello
}
```

---

### **8.2 Example with Lambda**

```cpp
function<int(int, int)> add = [](int a, int b) {
    return a + b;
};
cout << add(5, 3); // Output: 8
```

---

### **8.3 Example with Functor**

```cpp
struct Multiply {
    int operator()(int a, int b) { return a * b; }
};

int main() {
    function<int(int, int)> f = Multiply();
    cout << f(4, 5);
}
```

---

## **9. Practical Comparison**

| Type             | Syntax                                  | Flexibility | Inline | Can store state   |
| ---------------- | --------------------------------------- | ----------- | ------ | ----------------- |
| Normal Function  | `bool cmp(int, int)`                    | Simple      | No     | No                |
| Function Pointer | `sort(..., cmp)`                        | Basic       | No     | No                |
| Functor          | `struct Compare { bool operator()(); }` | High        | Yes    | Yes               |
| Lambda           | `[](int a, int b)`                      | Very High   | Yes    | Yes (via capture) |
| std::function    | `function<int(int,int)> f`              | Very High   | No     | Yes               |

---

## **10. Summary**

| Concept                 | Purpose                          | Example                                    |
| ----------------------- | -------------------------------- | ------------------------------------------ |
| **Function Pointer**    | Pass normal function             | `sort(v.begin(), v.end(), cmp)`            |
| **Functor**             | Object acting as function        | `sort(v.begin(), v.end(), greater<int>())` |
| **Predefined Functors** | Ready-to-use comparators         | `plus<>`, `greater<>`                      |
| **Lambda**              | Inline anonymous function        | `[](int a, int b){return a>b;}`            |
| **std::function**       | General-purpose function wrapper | `function<int(int,int)> f`                 |

---

## **Final Tip**

* Always prefer **lambda functions** for short logic.
* Use **functors** when logic is reused or needs internal state.
* `std::function` is great for flexibility, though slightly slower than lambdas/functors.

---

✅ **Now STL Notes are complete**:

1. Containers
2. Iterators
3. Algorithms
4. Functions & Functors