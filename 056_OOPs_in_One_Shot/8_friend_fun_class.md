# **FRIEND FUNCTION**

## **Concept**

A **friend function** is a non-member function that is allowed to access the **private** and **protected** members of a class.

Normally, only **member functions** can access private/protected data, but a friend function bypasses this rule.

---

## **Syntax**

```cpp
class ClassName {
private:
    int data;
    friend void fun(ClassName obj);   // declaration of friend function
};
```

---

## **Key Features**

| Feature      | Description                                                               |
| ------------ | ------------------------------------------------------------------------- |
| Keyword      | `friend`                                                                  |
| Not a member | Declared inside class but defined outside                                 |
| Access       | Can access private & protected data                                       |
| Calling      | Called like a normal function (not with object dot operator)              |
| Use case     | When two classes or external functions need direct access to private data |

---

## **Example**

```cpp
#include <iostream>
using namespace std;

class Test {
private:
    int x = 10;

public:
    friend void show(Test obj);
};

void show(Test obj) {
    cout << "value of x: " << obj.x << endl; // allowed because show() is friend
}

int main() {
    Test t;
    show(t);
    return 0;
}
```

---

## **Output**

```
value of x: 10
```

---

## **When to use friend function**

• Operator overloading between two objects
• When an external function needs access to private data
• Inter-class operations requiring intimate access

---

---

# **FRIEND CLASS**

## **Concept**

A **friend class** is a class whose **all member functions** get access to the private and protected data of another class.

If class B is a friend of class A → every function of B can access private/protected members of A.

---

## **Syntax**

```cpp
class A {
private:
    int data;
    friend class B;  // B becomes a friend class
};
```

---

## **Key Features**

| Feature     | Description                                       |
| ----------- | ------------------------------------------------- |
| Keyword     | `friend`                                          |
| Access      | Full access to private/protected of another class |
| Direction   | Friendship is **not bidirectional**               |
| Inheritance | Friendship is **not inherited**                   |
| Type        | Class-level friendship (all functions included)   |

---

## **Example**

```cpp
#include <iostream>
using namespace std;

class A {
private:
    int x = 20;
    friend class B;   // B is friend of A
};

class B {
public:
    void display(A obj) {
        cout << "value of x: " << obj.x << endl;
    }
};

int main() {
    A a;
    B b;
    b.display(a);
    return 0;
}
```

---

## **Output**

```
value of x: 20
```

---

---

# **Difference between Friend Function and Friend Class**

| Basis           | Friend Function                   | Friend Class                         |
| --------------- | --------------------------------- | ------------------------------------ |
| Definition      | Single function gets access       | Entire class gets access             |
| Scope of access | Only that function                | All member functions of friend class |
| Declaration     | Inside class                      | Inside class                         |
| Keyword         | `friend`                          | `friend class`                       |
| Called with     | Normal function call              | Through object of friend class       |
| Use cases       | When only 1 function needs access | When multiple functions need access  |

---

---

# **Important Points (Frequently Asked in Viva / Exams)**

✔ Friendship **breaks encapsulation partially**
✔ Friendship is **not inherited**
✔ Friendship is **not mutual**
 If A is friend of B → B is not automatically friend of A
✔ Friendship is **not transitive**
 If A is friend of B and B is friend of C → A is not friend of C
✔ Keyword `friend` can be used with:

* Normal function
* Member function of another class
* Whole class
* Operator overloading

---