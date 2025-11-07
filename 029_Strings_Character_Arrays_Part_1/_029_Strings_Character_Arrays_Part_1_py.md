# Strings Character Arrays Part 1

---

# **Python Strings (Part 1)**

---

## **1. Introduction to Strings**

A **string** in Python is a **sequence of characters** enclosed in **single quotes (' ')**, **double quotes (" ")**, or **triple quotes (''' ''' or """ """)**.

Examples:

```python
str1 = 'Hello'
str2 = "Python"
str3 = '''This is
a multiline
string.'''
```

### **Key points**

1. Strings are **immutable** in Python — once created, they cannot be changed.
2. Each character in a string has an **index** starting from 0.
3. Strings can store letters, numbers, or special characters.

---

## **2. Creating Strings**

Python allows creating strings in three main ways:

```python
# Single-line strings
name = "Shreya"
greet = 'Hello'

# Multi-line string
para = """This is
a multi-line
string example."""

# Empty string
empty = ""
```

---

## **3. String Indexing and Accessing Characters**

Each character in a string is indexed.
Indexing starts from **0** for the first character and **-1** for the last character.

Example:

```python
text = "Python"

print(text[0])   # P
print(text[2])   # t
print(text[-1])  # n (last character)
```

### **Note:**

If you try to access an index that doesn’t exist, Python raises an **IndexError**.

---

## **4. String Slicing**

Slicing allows you to access a **substring** (part of a string) using the syntax:

```python
string[start:end:step]
```

* `start`: index to begin from (inclusive)
* `end`: index to stop before (exclusive)
* `step`: gap between indices (default = 1)

Examples:

```python
s = "DataScience"

print(s[0:4])    # 'Data'  (characters from index 0 to 3)
print(s[:4])     # 'Data'  (start defaults to 0)
print(s[4:])     # 'Science' (till end)
print(s[-7:-1])  # 'Scienc'
print(s[::-1])   # 'ecneicSataD' (reversed string)
```

---

## **5. String Immutability**

In Python, strings **cannot be modified** once created.

```python
s = "Hello"
s[0] = 'J'   # ❌ Error (TypeError)
```

To modify, you must create a new string:

```python
s = "Hello"
s = "J" + s[1:]
print(s)  # "Jello"
```

---

## **6. String Concatenation and Repetition**

### **Concatenation (`+`)**

Joins two or more strings.

```python
s1 = "Data"
s2 = "Science"
result = s1 + " " + s2
print(result)  # Data Science
```

### **Repetition (`*`)**

Repeats the string multiple times.

```python
s = "Hi"
print(s * 3)  # HiHiHi
```

---

## **7. Looping Through a String**

Strings are iterable, so you can use loops to access each character.

```python
word = "Python"
for ch in word:
    print(ch)
```

Or with index:

```python
for i in range(len(word)):
    print(word[i])
```

---

## **8. Checking Membership**

Use `in` or `not in` to check if a substring exists in another string.

```python
s = "Machine Learning"

print("Learn" in s)     # True
print("AI" not in s)    # True
```

---

## **9. String Comparison**

Strings are compared **lexicographically** (character by character based on Unicode value).

```python
print("apple" == "apple")   # True
print("apple" < "banana")   # True
print("abc" > "Abc")        # True (lowercase > uppercase)
```

---

## **10. String Length**

Use the `len()` function.

```python
s = "Python"
print(len(s))  # 6
```

---

## **11. Escape Characters**

Used to represent special characters inside strings.

| Escape Sequence | Meaning      | Example Output                      |
| --------------- | ------------ | ----------------------------------- |
| `\n`            | New line     | `"Hello\nWorld"` → Hello <br> World |
| `\t`            | Tab space    | `"Name:\tShreya"` → Name: Shreya    |
| `\\`            | Backslash    | `"C:\\newfolder"` → C:\newfolder    |
| `\'`            | Single quote | `'It\'s fine'` → It’s fine          |
| `\"`            | Double quote | `"He said \"Hi\""` → He said "Hi"   |

---

## **12. Raw Strings**

To ignore escape sequences, prefix the string with `r` or `R`.

```python
path = r"C:\newfolder\data"
print(path)  # C:\newfolder\data
```

---

## **13. Multiline Strings**

You can write strings spanning multiple lines using triple quotes.

```python
msg = """This is
a multiline
string."""
print(msg)
```

---

## **14. Input from User**

Use the `input()` function to take string input.

```python
name = input("Enter your name: ")
print("Hello", name)
```

Note: `input()` always returns data as a **string**, even if you type numbers.

---

## **15. Type Conversion**

Convert between strings and other types using `str()`, `int()`, `float()`, etc.

```python
x = 10
y = str(x)  # '10'
z = int('25')  # 25
```

---

## **16. String Output Formatting (Basic)**

Using commas (default space separator):

```python
name = "Shreya"
age = 21
print("Name:", name, "Age:", age)
```

Or using **formatted strings (f-strings)**:

```python
print(f"My name is {name} and I am {age} years old.")
```

Output:

```
My name is Shreya and I am 21 years old.
```

---

## **17. Common String Errors**

| Error Type    | Example        | Cause                           |
| ------------- | -------------- | ------------------------------- |
| `TypeError`   | `'Age: ' + 21` | Cannot concatenate str with int |
| `IndexError`  | `"hello"[10]`  | Index out of range              |
| `SyntaxError` | `'hello" `     | Mismatched quotes               |

---