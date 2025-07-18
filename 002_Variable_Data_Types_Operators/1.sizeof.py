
import sys  # Required to use sys.getsizeof()

# -----------------------------------------------
# 🔹 Declaring variables of different data types
# -----------------------------------------------
a = 0           # Integer
b = 3.14        # Float (decimal number)
c = 'A'         # Character (actually a string of length 1 in Python)
d = True        # Boolean (True/False)
e = "Shreya"    # String (sequence of characters)

# -----------------------------------------------
# 🔹 Printing memory size using sys.getsizeof()
# -----------------------------------------------
print("Size of int:", sys.getsizeof(a), "bytes")        # Includes internal overhead
print("Size of float:", sys.getsizeof(b), "bytes")
print("Size of char:", sys.getsizeof(c), "bytes")       # 1-char string
print("Size of bool:", sys.getsizeof(d), "bytes")
print("Size of string:", sys.getsizeof(e), "bytes")     # Size increases with length

"""
-----------------------------------------------
📝 Notes:

1. In C++:
   - sizeof(type) gives exact memory size of data type (e.g., int = 4 bytes).
   - It's fixed for a given system/architecture.

2. In Python:
   - sys.getsizeof() returns the size of an **object in memory**.
   - It includes both:
     ✔ actual data size
     ✔ internal interpreter overhead

3. For example:
   - An empty string uses memory too (due to internal object structure).
   - A string’s size grows as the number of characters increases.

4. Data Types Mapped:
   - `int` ➝ Integer (like C++)
   - `float` ➝ Floating-point number
   - `str` ➝ String (char is just a 1-length string in Python)
   - `bool` ➝ Boolean (True/False)

5. Output may vary slightly based on:
   - Python version
   - Operating System
   - System architecture (32-bit/64-bit)

-----------------------------------------------
"""