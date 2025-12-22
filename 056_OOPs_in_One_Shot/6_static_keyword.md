## **STATIC KEYWORD — STATIC VARIABLES & STATIC OBJECTS (Quick Intro)**

* **Static Variable in Function** → created and initialized only once for the entire program lifetime. Value persists across function calls.
* **Static Variable in Class** → created and initialized only once for the class. Shared by all objects (one copy only).
* **Static Objects** → lifetime becomes the whole program. Even if created inside a block/function, they are destroyed only when the program ends.

---

## **STATIC KEYWORD IN C++**

`static` is a special storage-class specifier that **controls the lifetime, visibility, and sharing of variables and functions**.

It behaves differently based on where it is used:

1. **Inside functions (local static variable)**
2. **Inside classes (static data member)**
3. **Inside classes (static member function)**
4. **Global scope / file scope (internal linkage)**

---

## **1. Static Variable inside a Function**

A static variable **retains its value between multiple function calls**.

```cpp
void test() {
    static int x = 0;
    x++;
    cout << x << endl;
}

int main() {
    test(); //1
    test(); //2
    test(); //3
}
```

### Output

```
1
2
3
```

### Why this happens?

| Normal Local Variable     | Static Local Variable            |
| ------------------------- | -------------------------------- |
| Memory allocated on stack | Memory allocated in data segment |
| Created every call        | Created once                     |
| Destroyed after call      | Destroyed only when program ends |
| Value resets              | Value persists                   |

🔹 Static variables inside a function follow **local scope but global lifetime**
They are visible only within the function, yet remain alive as long as the program runs.

🔹 Initialization happens **only once**, no matter how many times the function is called.

🔹 They are useful for

* counters
* caching values between calls
* reducing repeated calculations

---

## **2. Static Data Members (Class Level Variable)**

A **static data member is shared among all objects of the class**.

Only **one copy** is created for the entire class.

```cpp
class Student {
public:
    static int count;
    Student() { count++; }
};

int Student::count = 0;
```

```cpp
int main() {
    Student s1, s2, s3;
    cout << Student::count; // prints 3
}
```

### Benefits

| Without static                            | With static                    |
| ----------------------------------------- | ------------------------------ |
| Separate copy of variable for each object | One shared copy                |
| Wastes memory                             | Saves memory                   |
| Hard to sync values                       | Easy to maintain shared values |

🔹 Static data members belong to the **class**, not to objects.
Even if no object is created, the static variable still exists in memory.

🔹 They can be accessed using the **class name**:

```cpp
cout << Student::count;
```

🔹 Definition using **scope resolution `::`** is required because memory for static data members is allocated **outside the class**, not inside it.

---

## **3. Static Member Function**

Static functions **do not depend on objects** and can be called using the class name.

```cpp
class Test {
public:
    static int x;
    static void show() {
        cout << x << endl;
    }
};
int Test::x = 100;
```

```cpp
int main() {
    Test::show();   // no object needed
}
```

### Rules

| Feature                | Allowed?      |
| ---------------------- | ------------- |
| Access static data     | ✔ Yes         |
| Access non-static data | ❌ No          |
| Call without object    | ✔ Yes         |
| Use `this` pointer     | ❌ Not allowed |

🔹 Static member functions are used when the logic is related to the **class as a whole**, not to a particular object.

🔹 They cannot use `this` because `this` belongs to an object, and static functions work **without objects**.

🔹 They are useful in:

* utility functions
* object counters
* configuration/settings
* singleton classes

---

## **4. Static Global Variable (Internal Linkage)**

If a global variable is declared static, it becomes **accessible only in that file**, not other files.

```cpp
static int x = 10;   // file-level scope
```

Used to **avoid naming conflicts in multi-file projects**.

🔹 Without `static`, a global variable has **external linkage**, meaning it can be used across multiple files with `extern`.

🔹 With `static`, the variable’s visibility becomes **restricted to the same file**, improving encapsulation.

🔹 Many large projects use static global variables to provide **private global data** without exposing it to other files.

---

## **5. Memory Location of Static**

| Type                   | Stored in                      |
| ---------------------- | ------------------------------ |
| static inside function | Data segment                   |
| static data member     | Data segment                   |
| non-static variable    | Stack (local) / Heap (dynamic) |

Static memory lives **until the program terminates**.

🔹 Although static variables may have different scopes (local, class, global), their **lifetime is always entire program execution**.

🔹 Only **one-time initialization** of static variables improves performance — especially when dealing with complex objects or expensive operations.

🔹 Static variables are initialized **only once**, before execution enters `main()` (also called static initialization phase).

---

### Extra summary for last-moment revision

| Where used             | Scope           | Lifetime       | Sharing                 |
| ---------------------- | --------------- | -------------- | ----------------------- |
| Static inside function | Within function | Entire program | Not shared              |
| Static data member     | Within class    | Entire program | Shared by all objects   |
| Static global variable | Within file     | Entire program | Not shared outside file |

---
---

## **6. Static Keyword Use Cases**

| Use Case                 | Description                    |
| ------------------------ | ------------------------------ |
| Global counters          | Counting objects               |
| Common configuration     | Shared constants               |
| Singleton design pattern | Ensures only one instance      |
| Caching                  | Store persistent computed data |
| Logging                  | Shared logging state           |

---

## **7. Static vs Non-Static (Class Members)**

| Attribute               | Static              | Non-Static          |
| ----------------------- | ------------------- | ------------------- |
| Memory                  | One for whole class | One per object      |
| Access                  | Class name / object | Only via object     |
| Lifetime                | Entire program      | Until object exists |
| Can access all members? | ❌ Only static       | ✔ Yes               |

---

## **8. Interview Favourite Questions**

| Question                                      | Correct Answer          |
| --------------------------------------------- | ----------------------- |
| Can static function access non-static member? | No                      |
| Can static member function be virtual?        | No                      |
| Where static data member is initialized?      | Outside class           |
| Memory of static variable created where?      | Data segment            |
| Can you call static function using object?    | Yes (but not necessary) |
| Can a static variable be private?             | Yes                     |

---

## **9. Static + Object Counter Example**

```cpp
class Employee {
private:
    static int total;
public:
    Employee() { total++; }
    static void count() {
        cout << "Total employees: " << total << endl;
    }
};
int Employee::total = 0;

int main() {
    Employee e1, e2, e3;
    Employee::count();
}
```

### Output

```
Total employees: 3
```

---

## **10. Final Key Takeaways**

* `static` **preserves value** inside functions.
* `static` class variables are **shared among objects**.
* `static` member functions can be **called without object**.
* `static` global variables have **internal linkage** (file scope).
* Memory of static objects stays **throughout program execution**.

---