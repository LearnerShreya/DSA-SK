

> **What does `int& a` mean in C++?**


### ✅ **Short Answer:**

`int &a` means **`a` is a reference to an integer**, not a copy.



### 🔍 **In Detail:**

| Type     | Meaning                                                                        |
| -------- | ------------------------------------------------------------------------------ |
| `int a`  | `a` is a **copy** of the value passed (changes don’t affect original).         |
| `int& a` | `a` is a **reference** to the original (changes affect the caller's variable). |


### 🧪 Example:

```cpp
#include <iostream>
using namespace std;

void updateByValue(int x) {
    x = x + 10;
}

void updateByReference(int &x) {
    x = x + 10;
}

int main() {
    int num = 5;

    updateByValue(num);
    cout << "After by value: " << num << endl;  // Output: 5

    updateByReference(num);
    cout << "After by reference: " << num << endl;  // Output: 15

    return 0;
}
```

---

### 🧠 **What’s Happening?**

* `updateByValue(int x)` → takes a **copy**, so changes don’t affect the original.
* `updateByReference(int &x)` → takes a **reference**, so changes affect `num` directly.

---
