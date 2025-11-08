# Strings Character Arrays Part 1

---

# STRINGS IN C++

---

## 1. What is a String?

In programming, a **string** is a sequence of characters (letters, numbers, symbols, or spaces) stored together to represent text.

Examples:

```cpp
"Hello"
"Shreya Singh"
"I love C++"
```

A string is **not a basic data type** in C++ — it’s made using either:

1. **Character arrays (C-Style strings)**
2. **The `string` class (C++ STL)**

So when we say *string*, we might mean either of these depending on context.

---

## 2. CHARACTER ARRAYS (C-STYLE STRINGS)

Before C++ introduced the `string` class, C language handled text using **character arrays**.

---

### 2.1 Declaration and Initialization

A **character array** is declared as:

```cpp
char str[10];
```

You can initialize it in two main ways:

**Method 1 (manual initialization):**

```cpp
char name[] = {'A', 'p', 'n', 'a', '\0'};
```

**Method 2 (string literal):**

```cpp
char name[] = "Apna";
```

The compiler automatically adds `'\0'` (null character) at the end to mark the end of the string.

---

### 2.2 Understanding `'\0'` (Null Character)

This is extremely important.
The null character tells the compiler where the string ends in memory.
Without it, the program doesn’t know when to stop reading characters.

**Example:**

```cpp
char str[] = {'A', 'p', 'n', 'a'};
cout << str;  // Undefined output (no '\0')
```

Here, since there’s no null character, `cout` keeps printing memory beyond the intended array.

---

### 2.3 Memory Layout

Let’s see how `"Apna"` is stored in memory:

| Index | 0 | 1 | 2 | 3 | 4  |
| ----- | - | - | - | - | -- |
| Value | A | p | n | a | \0 |

When you print the string, `cout` starts from index 0 and stops when it finds `'\0'`.

---

## 3. INPUT AND OUTPUT WITH CHARACTER ARRAYS

### 3.1 Using `cin`

```cpp
char name[50];
cin >> name;
```

If you input:

```
Apna College
```

Stored value: `"Apna"`
Reason: `cin` stops reading when it encounters a **space**, **tab**, or **newline**.

So `cin` is only for **single-word input**.

---

### 3.2 Using `cin.getline()`

If you want to read a complete sentence (with spaces):

```cpp
cin.getline(name, 50);
```

Explanation:

* Reads up to 49 characters or until a newline (`\n`) is found.
* Automatically adds a null character `'\0'` at the end.

**Example:**

```
Input:  I love programming
Output stored:  I love programming
```

You can also use a **custom delimiter** instead of newline.

```cpp
cin.getline(name, 50, '$');
```

This will stop reading when `$` is found.

**Input:**
`C++ is fun$Python is powerful`

**Stored:**
`C++ is fun`

---

### 3.3 `cin.get()` vs `cin.getline()`

| Function        | Stops At                      | Includes newline?  | Allows spaces? | Clears newline? |
| --------------- | ----------------------------- | ------------------ | -------------- | --------------- |
| `cin`           | space / newline               | No                 | No             | Yes             |
| `cin.get()`     | newline                       | Keeps it in buffer | Yes            | No              |
| `cin.getline()` | newline (or custom delimiter) | Discards newline   | Yes            | Yes             |

Example:

```cpp
char line[100];
cin.get(line, 100);
cout << line;
```

This will read until newline, but newline will **remain in input buffer**, so you might need `cin.ignore()` before next input.

---

## 4. STRING LENGTH

### 4.1 Manual Counting

```cpp
char str[] = "Shreya";
int len = 0;
for (int i = 0; str[i] != '\0'; i++) {
    len++;
}
cout << "Length: " << len;
```

Output:

```
Length: 6
```

### 4.2 Using Library Function

Include header `<cstring>` to use built-in functions.

```cpp
#include <cstring>
cout << strlen(str);
```

This function counts characters until it finds `'\0'`.
It doesn’t count the null character itself.

---

## 5. COMMON C-STRING FUNCTIONS (from `<cstring>`)

| **Function**                         | **Purpose**                                                    | **Example**                                | **Result / Return Value**                                                |
| ------------------------------------ | -------------------------------------------------------------- | ------------------------------------------ | ------------------------------------------------------------------------ |
| `strlen(str)`                        | Returns the **length** of the string (excluding `'\0'`)        | `strlen("hello")`                          | `5`                                                                      |
| `strcpy(dest, src)`                  | Copies **source string** (`src`) into **destination** (`dest`) | `strcpy(a, "world")`                       | `a` becomes `"world"`                                                    |
| `strcat(a, b)`                       | Appends string `b` **to the end** of string `a`                | `strcat(a, "College")` where `a = "Apna "` | `"Apna College"`                                                         |
| `strcmp(a, b)`                       | **Compares** two strings lexicographically                     | `strcmp("apple", "apple")`                 | Returns `0` (same) <br> Returns `<0` if a < b <br> Returns `>0` if a > b |
| `strchr(str, ch)`                    | Finds the **first occurrence** of character `ch`               | `strchr("apple", 'p')`                     | Pointer to first `'p'` (→ `"pple"`)                                      |
| `strrev(str)` *(compiler dependent)* | **Reverses** the given string                                  | `strrev("abc")`                            | `"cba"`                                                                  |


Example:

```cpp
char s1[50] = "Apna";
char s2[] = "College";

strcat(s1, s2);
cout << s1;  // ApnaCollege
```


| **Expression**      | **Meaning**                                  | **Example**                 | **Result**                 |
| ------------------- | -------------------------------------------- | --------------------------- | -------------------------- |
| `strcmp(a, b) == 0` | Both strings are **exactly the same**        | `strcmp("apple", "apple")`  | `0`                        |
| `strcmp(a, b) < 0`  | `a` comes **before** `b` in dictionary order | `strcmp("apple", "banana")` | negative value (like `-1`) |
| `strcmp(a, b) > 0`  | `a` comes **after** `b` in dictionary order  | `strcmp("mango", "apple")`  | positive value (like `1`)  |

So in short:

* `0` → strings are equal
* negative → first string is smaller (alphabetically before)
* positive → first string is greater (alphabetically after)

---

## 6. LIMITATIONS OF CHARACTER ARRAYS

1. **Fixed size:** Cannot expand dynamically.
2. **No direct assignment:**
   `str = "Hello";` → Invalid.
3. **Manual memory management:** Need to use functions like `strcpy`, `strcat`, etc.
4. **Null character issues:** Forgetting `'\0'` can cause undefined behavior.
5. **Limited flexibility** compared to modern string handling.

Because of these issues, C++ introduced the **string class**.

---

## 7. C++ STRING CLASS (Header: `<string>`)

The modern and safer alternative to character arrays.

---

### 7.1 Declaration

```cpp
#include <string>
string s = "Apna College";
```

No need for `'\0'`. The string class internally manages size and termination.

---

### 7.2 Dynamic Behavior

C++ strings can **grow or shrink dynamically** during runtime.

Example:

```cpp
string s = "Apna";
s = "Hello"; // allowed
```

In contrast, this doesn’t work for C-strings:

```cpp
char s[] = "Apna";
s = "Hello"; // ❌ invalid
```

---

### 7.3 Basic Operations

| **Operation**        | **Syntax**                   | **Example**                       | **Result / Output**                   |
| -------------------- | ---------------------------- | --------------------------------- | ------------------------------------- |
| **Print**            | `cout << s;`                 | `string s = "Hello"; cout << s;`  | Prints `Hello`                        |
| **Input (one word)** | `cin >> s;`                  | Input: `Apna College`             | Stores only `Apna`                    |
| **Input (sentence)** | `getline(cin, s);`           | Input: `Apna College`             | Stores entire line → `"Apna College"` |
| **Length**           | `s.length()` or `s.size()`   | `string s = "Hello"; s.length();` | Returns `5`                           |
| **Reassign**         | `s = "New";`                 | If `s = "Old"; s = "New";`        | Changes value of `s` to `"New"`       |
| **Concatenate**      | `s1 + s2` or `s1.append(s2)` | `"Apna" + "College"`              | `"ApnaCollege"`                       |

---

### 7.4 Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Apna";
    string college = " College";
    
    string full = name + college;
    cout << "Full: " << full << endl;
    
    cout << "Length: " << full.length() << endl;

    full = "Hello";
    cout << "After reassign: " << full << endl;

    return 0;
}
```

**Output:**

```
Full: Apna College
Length: 12
After reassign: Hello
```

---

### 7.5 Comparison Table (C-String vs C++ String)

| Feature             | Character Array | C++ String          |
| ------------------- | --------------- | ------------------- |
| Header File         | `<cstring>`     | `<string>`          |
| Size                | Fixed           | Dynamic             |
| Reassignment        | Not allowed     | Allowed             |
| Null Character      | Required        | Managed internally  |
| Input (with spaces) | `cin.getline()` | `getline(cin, str)` |
| Comparison          | `strcmp()`      | `==`                |
| Concatenation       | `strcat()`      | `+`                 |
| Length              | `strlen()`      | `.length()`         |
| Copy                | `strcpy()`      | `=`                 |

---

## 8. Example Program (Comparing Both)

```cpp
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    // Character Array
    char str1[20] = "Hello";
    cout << "C-String: " << str1 << endl;
    cout << "Length: " << strlen(str1) << endl;

    // C++ String
    string str2 = "Hello World";
    cout << "C++ String: " << str2 << endl;
    cout << "Length: " << str2.length() << endl;

    str2 = "College";
    cout << "After reassign: " << str2 << endl;
}
```

**Output:**

```
C-String: Hello
Length: 5
C++ String: Hello World
Length: 11
After reassign: College
```

---