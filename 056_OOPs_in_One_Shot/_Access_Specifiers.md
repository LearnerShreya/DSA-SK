
# **Access Specifiers Table**

| Feature                             | public                              | private                            | protected                                                        |
| ----------------------------------- | ----------------------------------- | ---------------------------------- | ---------------------------------------------------------------- |
| Access inside class                 | Yes                                 | Yes                                | Yes                                                              |
| Access in child class (inheritance) | Yes                                 | No                                 | Yes                                                              |
| Access outside class (normal code)  | Yes                                 | No                                 | No                                                               |
| Default access in class             | No                                  | Yes                                | No                                                               |
| Default access in struct            | Yes                                 | No                                 | No                                                               |
| Usage                               | When you want full access           | When you want full security        | When you want access only for class + derived classes            |
| Real-world example                  | A public park (everyone can access) | Your ATM PIN (only you can access) | Your home’s internal rooms (family can access, outsiders cannot) |

---

# **Effect of Mode of Inheritance**

If class B inherits class A using different modes:

| Base Class Member | public inheritance   | protected inheritance | private inheritance |
| ----------------- | -------------------- | --------------------- | ------------------- |
| public in base    | public in derived    | protected in derived  | private in derived  |
| protected in base | protected in derived | protected in derived  | private in derived  |
| private in base   | not accessible       | not accessible        | not accessible      |

---
---

# **CODE EXAMPLE — Access Specifiers + Modes of Inheritance**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int pub_var;         // public
private:
    int pri_var;         // private
protected:
    int pro_var;         // protected

public:
    Base() {
        pub_var = 10;
        pri_var = 20;
        pro_var = 30;
    }

    void showBase() {
        cout << "Inside Base class:" << endl;
        cout << "Public: " << pub_var << endl;
        cout << "Private: " << pri_var << endl;
        cout << "Protected: " << pro_var << endl;
    }
};

// ------------------------------------------------------
// PUBLIC INHERITANCE
// ------------------------------------------------------
class DerivedPublic : public Base {
public:
    void show() {
        cout << "\nPublic Inheritance:" << endl;
        cout << "Public: " << pub_var << endl;      // accessible
        // cout << pri_var;    // NOT accessible
        cout << "Protected: " << pro_var << endl;   // accessible
    }
};

// ------------------------------------------------------
// PROTECTED INHERITANCE
// ------------------------------------------------------
class DerivedProtected : protected Base {
public:
    void show() {
        cout << "\nProtected Inheritance:" << endl;
        cout << "Public (becomes protected): " << pub_var << endl;
        // cout << pri_var;    // NOT accessible
        cout << "Protected: " << pro_var << endl;
    }
};

// ------------------------------------------------------
// PRIVATE INHERITANCE
// ------------------------------------------------------
class DerivedPrivate : private Base {
public:
    void show() {
        cout << "\nPrivate Inheritance:" << endl;
        cout << "Public (becomes private): " << pub_var << endl;
        // cout << pri_var;    // NOT accessible
        cout << "Protected (becomes private): " << pro_var << endl;
    }
};

int main() {
    Base b;
    b.showBase();

    DerivedPublic dp;
    dp.show();
    cout << "Accessing public member from object: " << dp.pub_var << endl;

    DerivedProtected dpro;
    dpro.show();
    // dpro.pub_var;   // NOT accessible

    DerivedPrivate dpri;
    dpri.show();
    // dpri.pub_var;   // NOT accessible

    return 0;
}
```

---

# **OUTPUT EXPLANATION**

### **Inside Base class**

All members are accessible because they are inside the class itself.

### **Public Inheritance**

* public stays public
* protected stays protected
* private is not accessible

### **Protected Inheritance**

* public → protected
* protected → protected
* private → not accessible

### **Private Inheritance**

* public → private
* protected → private
* private → not accessible

### **Outside Class**

* Only `dp.pub_var` (from public inheritance) is accessible
* Others not allowed

---