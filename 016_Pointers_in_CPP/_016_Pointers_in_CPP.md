# Pointers in CPP

# 📘 Part 1 – Basics & Foundation

---

## 🔹 1. Introduction

* A **pointer** is a variable that stores the **memory address** of another variable.
* Unlike normal variables which hold values, pointers hold **locations** where those values live in memory.

👉 Why Pointers?

* Efficient in memory management
* Essential for **dynamic memory allocation**
* Help in **pass by reference**
* Work with **arrays, strings, structures, and functions**
* Provide low-level control over memory (like C)



Okay Shreya 💙 let me explain this in the **most beginner-friendly way**.

---

## 🌱 Why did **pointers** even come into programming?

Imagine you’re working in C (a low-level language close to machine). At that time, memory (RAM) was **small and expensive**, so programmers needed a way to **directly control memory** instead of just blindly storing values.

So, **pointers were invented** to:

* Point to (or store the address of) a place in memory.
* Give programmers **direct access and control** over memory.

---

## 🏡 Simple Analogy: House and Address

Think of memory as a big colony full of houses.

* Each **house** = a memory location that stores some data.
* Each **address of the house** = a number (location in memory).
* A **pointer** = a slip of paper that stores the *address of a house*.

Now, instead of carrying the whole house (data) around, you just carry the slip (pointer). Whenever you need, you go directly to that house using the slip.

---

## Why is this useful?

1. **Efficient memory use**
   You don’t always need to copy the whole data. Just pass the address (like sharing the slip of paper instead of carrying the furniture).

2. **Dynamic memory allocation**
   Sometimes you don’t know how much space you’ll need (like you don’t know how many guests will come). With pointers, you can **reserve memory on the fly** and free it when not needed.

3. **Pass by reference**
   Functions can directly change the original data (instead of working with a copy). Example: a doctor directly treating you, not just your photo.

4. **Work with arrays and strings**
   Arrays and strings are just *continuous blocks of memory*. Pointers let you walk through them easily like moving house-to-house with the address slip.

5. **Low-level control**
   Sometimes you need to manage memory very precisely (like in operating systems, drivers, or embedded systems). Pointers give you that power.

✅ In short:
Pointers came because programmers needed a way to **talk to memory directly**. They’re important because they give **control, flexibility, and efficiency** in managing data.

---

---

## 🔹 2. Memory Address

Every variable lives in memory and has:

* **Value** → the actual stored number/character.
* **Address** → location (a hex number like `0x61ff0c`).

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 42;
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
}
```

---

## 🔹 3. Pointer Declaration & Initialization

Syntax:

```cpp
datatype* pointer_name;
```

Examples:

```cpp
int* p;      // pointer to int
char* c;     // pointer to char
float* f;    // pointer to float
```

👉 Initialization:

```cpp
int a = 10;
int* p = &a;   // stores address of a
```

---
---

## 🔹 4. Address (&) and Dereference (*) Operators

* **&** → gives address of variable.
* ***** → gives value stored at address (dereferencing).

```cpp
int y = 50;
int* p = &y;

cout << &y;   // prints address of y
cout << p;    // prints same address
cout << *p;   // prints 50 (value at that address)
```

---

## Step 1: `int y = 50;`

* You declare an integer `y`.
* The computer **allocates a chunk of memory** (usually 4 bytes for `int`) to store the value `50`.
* Let’s say the memory location assigned is **0x61ff0c** (just an example).

**Memory diagram:**

| Address  | Value |
| -------- | ----- |
| 0x61ff0c | 50    |

---

## Step 2: `int* p = &y;`

* `int* p` declares a **pointer to an integer**.
* `&y` gives the **address of `y`**, which is `0x61ff0c`.
* So now `p` **stores the address of `y`**, not the value `50`.

**Memory diagram:**

| Variable | Address  | Value    |                         |
| -------- | -------- | -------- | ----------------------- |
| y        | 0x61ff0c | 50       |                         |
| p        | 0x61ff08 | 0x61ff0c | ← stores address of `y` |

---

## Step 3: `cout << &y;`

* `&y` → the **address of y**.
* So it prints: `0x61ff0c` (or whatever the system assigned).
* This shows **where y lives in memory**.

---

## Step 4: `cout << p;`

* `p` **stores the address of `y`**, which is `0x61ff0c`.
* So printing `p` also prints the **same address** as `&y`.

💡 Key idea: A pointer **holds the location of a variable**, not its value.

---

## Step 5: `cout << *p;`

* `*p` → **dereferencing the pointer**.
* Dereferencing means: “Go to the memory location stored in `p` and fetch the value there.”
* `p` stores `0x61ff0c` → that address contains `50`.
* So `*p` prints `50`.

**Memory diagram (conceptually):**

```
y → 50 @ 0x61ff0c
p → 0x61ff0c
*p → 50
```

---

### 🔑 First-Principles Takeaways:

1. **Variables are stored in memory** → each has a unique address.
2. `&variable` → asks: “Where in memory is this variable?”
3. `pointer` → a variable whose **value is an address**.
4. `*pointer` → dereference → go to the stored address and **get the value there**.
5. Printing a pointer prints the address; dereferencing prints the value stored **at that address**.

---

---

## 🔹 5. Pointer to Pointer

A pointer can store the address of another pointer.

```cpp
int a = 100;
int* p = &a;
int** q = &p;

cout << a << endl;    // 100
cout << *p << endl;   // 100
cout << **q << endl;  // 100
```

👉 Memory chain:
`q → p → a → value`

---

## 🔹 6. Null Pointer

* A pointer that points to **nothing** (0).
* Prevents unexpected behavior.

```cpp
int* p = NULL;   // or int* p = 0;
if (p == NULL) cout << "Pointer is empty";
```

⚠️ Uninitialized pointers contain **garbage address** (dangerous).

---

## 🔹 7. Output-Based Questions (Basic)

👉 Predict the outputs:

```cpp
int a = 20;
int* p = &a;

cout << *p << endl;   // ?
cout << p << endl;    // ?
cout << &p << endl;   // ?
```

Answer:

* `*p` → 20
* `p` → address of `a`
* `&p` → address of pointer variable

---

## 🔹 8. Pass by Reference

### (a) Using Pointers

```cpp
void update(int* p) {
    *p = *p + 10;
}
int main() {
    int x = 5;
    update(&x);
    cout << x;   // 15
}
```

### (b) Using Reference Variable (Alias)

```cpp
void update(int& r) {
    r = r + 10;
}
int main() {
    int x = 5;
    update(x);
    cout << x;   // 15
}
```

👉 Both change the original variable.
References are safer & modern → Pointers are more flexible.

---

## 🔹 9. Array and Pointer Basics

* Array name itself is a **constant pointer** to its first element.

```cpp
int arr[3] = {10, 20, 30};
int* p = arr;   // same as &arr[0]

cout << *p << endl;     // 10
cout << *(p+1) << endl; // 20
cout << *(p+2) << endl; // 30
```

⚠️ Array name cannot be reassigned.

---

## 🔹 10. Pointer Arithmetic

Pointers can be moved using arithmetic:

* `p++` → move to next element
* `p--` → move back
* `p+n` → jump n elements forward
* `p-n` → jump n elements backward

Example:

```cpp
int arr[] = {1, 2, 3};
int* p = arr;

cout << *p << endl;     // 1
cout << *(p+1) << endl; // 2

p++;
cout << *p << endl;     // 2
```

👉 Movement depends on **data type size**:

* `int* p; p+1` → moves 4 bytes (on 32-bit).
* `char* p; p+1` → moves 1 byte.

---

## 🔹 11. Output Questions (Tricky with Arrays)

```cpp
int arr[] = {5, 10, 15};
int* p = arr;

cout << *p << endl;      // 5
cout << *(p+1) << endl;  // 10
cout << *(++p) << endl;  // 10
cout << *p++ << endl;    // 10 (then moves to next)
cout << *p << endl;      // 15
```

---
---

# 📘 Pointers in C++ (Part 2 – Advanced Concepts)

---

## 🔹 1. Dynamic Memory Allocation

Unlike normal variables, we can allocate memory **at runtime** using `new` and free it with `delete`.

### (a) Single Variable

```cpp
int* p = new int;   // allocates memory
*p = 50;
cout << *p;         // 50
delete p;           // free memory
```

### (b) Array

```cpp
int* arr = new int[5];   // array of 5 ints
for (int i = 0; i < 5; i++) arr[i] = i+1;

for (int i = 0; i < 5; i++) cout << arr[i] << " ";  // 1 2 3 4 5
delete[] arr;   // free array
```

👉 If you forget `delete`, you cause a **memory leak**.

---

## 🔹 2. Void Pointer

* A pointer that can point to **any type** of data.
* Must be **typecast** before dereferencing.

```cpp
void* ptr;
int x = 100;
ptr = &x;

cout << *(int*)ptr;   // 100
```

---

## 🔹 3. Function Pointer

A pointer can store the address of a function.

```cpp
#include <iostream>
using namespace std;

void greet() {
    cout << "Hello Shreya!";
}
int main() {
    void (*fp)() = greet;   // function pointer
    fp();                   // calls greet()
}
```

👉 Useful in **callback functions**, **event handling**, and **function tables**.

---

## 🔹 4. Pointer to Structure

Accessing structures using pointers:

```cpp
struct Student {
    int roll;
    char grade;
};

int main() {
    Student s1 = {101, 'A'};
    Student* p = &s1;

    cout << p->roll << endl;   // 101
    cout << p->grade << endl;  // A
}
```

👉 Use `->` instead of `.` with pointers.

---

## 🔹 5. Pointers and 2D Arrays

### (a) Normal 2D Array

```cpp
int arr[2][3] = {{1,2,3}, {4,5,6}};
cout << arr[0][0];     // 1
cout << *arr[0];       // 1
cout << *(*(arr+1)+2); // 6
```

### (b) Dynamic 2D Array

```cpp
int** mat = new int*[2];   // 2 rows
for (int i = 0; i < 2; i++) {
    mat[i] = new int[3];   // 3 cols
}

mat[0][0] = 10; mat[1][2] = 20;

cout << mat[0][0] << " " << mat[1][2]; // 10 20

// free memory
for (int i = 0; i < 2; i++) delete[] mat[i];
delete[] mat;
```

---

## 🔹 6. Pointers and Strings

C-style strings are **character arrays**. A `char*` points to the first character.

```cpp
char str[] = "Hello";
char* p = str;

cout << *p << endl;     // H
cout << *(p+1) << endl; // e
```

👉 String literals:

```cpp
char* s = "World";   // stored in read-only section
cout << s;
```

⚠️ Modifying string literals via pointers = **Undefined Behavior**.

---

## 🔹 7. More Output Questions (Tricky)

👉 Q1

```cpp
int x = 5;
int* p = &x;
int* q = p;

*q = *q + 5;
cout << x << " " << *p << " " << *q;
```

Answer → `10 10 10`

👉 Q2

```cpp
int a[] = {1,2,3,4};
int* p = a;

cout << *p << " ";     // 1
cout << *(p+2) << " "; // 3
cout << *(a+3);        // 4
```

👉 Q3

```cpp
int arr[] = {10,20,30};
int* p = arr;
cout << *p++ << " ";   // 10
cout << *++p << " ";   // 30
```

---

## 🔹 8. Pointers with Const

```cpp
const int x = 100;
const int* p = &x;   // pointer to const (value can’t change via p)
int y = 200;
int* const q = &y;   // const pointer (address can’t change)
```

---

## 🔹 9. Practical Use-Cases

1. **Dynamic Memory (malloc/new)**
2. **Arrays and Strings handling**
3. **Pass by reference in functions**
4. **Data structures (linked list, tree, graph)**
5. **Function callbacks & event handling**

---
---

# 📘 Pointers in C++ (Part 3 – Smart Pointers, Pitfalls & Cheat Sheet)

---

## 🔹 1. Dangling, Wild, and Null Pointers

| Pointer Type         | Description                                      | Example                                             |
| -------------------- | ------------------------------------------------ | --------------------------------------------------- |
| **Dangling Pointer** | Points to memory that has been deleted/freed.    | `int* p = new int(5); delete p; cout << *p;` (❌ UB) |
| **Wild Pointer**     | Uninitialized pointer pointing to random memory. | `int* p; cout << *p;` (❌ UB)                        |
| **Null Pointer**     | Points to nothing; safe to check before using.   | `int* p = NULL; if(p) *p = 10;` ✅                   |

✅ **Good Practice:** Always initialize pointers and set deleted pointers to `NULL`.

---

## 🔹 2. Smart Pointers (C++11+)

Modern C++ prefers **smart pointers** to avoid memory leaks. Defined in `<memory>`.

1. **unique_ptr** – single ownership

```cpp
#include <memory>
unique_ptr<int> p1(new int(10));
cout << *p1 << endl;
// automatic delete when out of scope
```

2. **shared_ptr** – multiple owners

```cpp
#include <memory>
shared_ptr<int> p2 = make_shared<int>(20);
shared_ptr<int> p3 = p2;   // reference count increases
```

3. **weak_ptr** – non-owning pointer (prevents circular reference)

```cpp
weak_ptr<int> wp = p3;   // does not increase ref count
```

✅ **Advantage:** Automatic memory management, avoids leaks, safer than raw pointers.

---

## 🔹 3. Memory Leaks and Safe Practices

* **Memory Leak:** Memory allocated via `new` or `malloc` is not freed.
* **Avoiding leaks:**

  * Always `delete` or `delete[]` after `new`.
  * Prefer **smart pointers**.
  * Set dangling pointers to `NULL`.

---

## 🔹 4. Top Interview/Tricky Questions

### Q1: What’s the output?

```cpp
int a[] = {1,2,3};
int* p = a;
cout << *p++ << " " << *p << endl;
```

**Answer:** `1 2` → Post-increment moves pointer **after** dereferencing.

### Q2: Pointer to function

```cpp
void fun(int x){ cout << x; }
int main() {
    void (*fp)(int) = fun;
    fp(10);
}
```

**Answer:** `10` → function called via pointer.

### Q3: Pointer + Array

```cpp
int arr[] = {10,20,30};
int* p = arr;
cout << *(p+2) - *(p) << endl;
```

**Answer:** `30-10 = 20`

### Q4: Dangling pointer

```cpp
int* p = new int(5);
delete p;
p = nullptr;
```

* Safe now, no UB.

---

## 🔹 5. Pointers vs References (Quick Comparison)

| Feature            | Pointer                | Reference                |
| ------------------ | ---------------------- | ------------------------ |
| Can be NULL?       | Yes                    | No                       |
| Can be reassigned? | Yes                    | No                       |
| Memory Usage       | Extra pointer memory   | No extra memory          |
| Syntax             | `*p`, `&`              | `&` in declaration       |
| Useful for         | Dynamic memory, arrays | Pass by reference, alias |

---

## 🔹 6. Visual Cheat Sheet (Memory + Pointer Diagram)

```
int x = 10;
int* p = &x;
int** q = &p;

Memory Layout:

x: 10        (Address: 0x61ff0c)
p: 0x61ff0c  (Address: 0x61ff08)
q: 0x61ff08  (Address: 0x61ff04)

*q → p → x → value
```

**Array + Pointer Arithmetic:**

```
int arr[3] = {5,10,15};
arr → points to arr[0]

arr[0] = 5  *(arr+0)
arr[1] = 10 *(arr+1)
arr[2] = 15 *(arr+2)
```

---

## 🔹 7. Summary Table (Everything at a Glance)

| Concept               | Key Points                                                |
| --------------------- | --------------------------------------------------------- |
| Pointer               | Stores address of variable                                |
| `*` operator          | Dereference, access value at address                      |
| `&` operator          | Get address of variable                                   |
| Pointer to Pointer    | Pointer storing address of another pointer                |
| Null Pointer          | Points to nothing, safe check                             |
| Dangling/Wild Pointer | UB, avoid by initializing and nulling                     |
| Pointer Arithmetic    | +, -, ++, -- based on data type                           |
| Arrays + Pointer      | Array name → pointer to first element                     |
| Dynamic Memory        | `new`, `delete`                                           |
| Function Pointer      | Stores function address                                   |
| Pointer to Structure  | Use `->` to access members                                |
| Smart Pointers        | `unique_ptr`, `shared_ptr`, `weak_ptr`                    |
| Reference (Alias)     | Safer alternative for pass by reference                   |
| Good Practice         | Always initialize, delete memory, avoid dangling pointers |

---

1. **Basics, foundation, dereference, arrays, arithmetic, outputs**
2. **Advanced pointers, dynamic memory, void pointers, function pointers, structures, 2D arrays, strings**
3. **Smart pointers, pitfalls, memory leaks, interview Qs, cheat sheet**