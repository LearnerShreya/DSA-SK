#include <iostream>  // Header for input-output operations
using namespace std;

int main() {
    // ----------------------------------------------
    // 🔹 Using sizeof with data types directly
    // ----------------------------------------------
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;      // Typically 4 bytes
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;  // Typically 4 bytes
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;// Typically 8 bytes
    cout << "Size of char: " << sizeof(char) << " byte" << endl;     // Always 1 byte
    cout << "Size of bool: " << sizeof(bool) << " byte" << endl;     // Usually 1 byte

    // ----------------------------------------------
    // 🔹 Declaring constants using const keyword
    // ----------------------------------------------
    // const means the variable's value cannot be changed after assignment
    const int a = 0;
    const float b = 0.0f;
    const double c = 0.0;
    const char d = 'A';
    const bool e = true;

    // ----------------------------------------------
    // 🔹 Using sizeof with constant variables
    // ----------------------------------------------
    cout << "Size of int (const a): " << sizeof(a) << " bytes" << endl;
    cout << "Size of float (const b): " << sizeof(b) << " bytes" << endl;
    cout << "Size of double (const c): " << sizeof(c) << " bytes" << endl;
    cout << "Size of char (const d): " << sizeof(d) << " byte" << endl;
    cout << "Size of bool (const e): " << sizeof(e) << " byte" << endl;

    return 0;
}

/*
-----------------------------------------------
🔍 Notes:

1. sizeof(type) ➝ Tells the memory (RAM) size occupied by a data type.
   Example: sizeof(int) usually returns 4.

2. sizeof(variable) ➝ Also works the same way.
   Example: sizeof(a) is same as sizeof(int) if a is of type int.

3. const keyword ➝ Used to make variables constant (read-only).
   You can still use sizeof on const variables.

4. Sizes of data types may vary depending on:
   - System architecture (32-bit vs 64-bit)
   - Compiler being used

5. char and bool are usually 1 byte.
   double is often 8 bytes, float is 4 bytes.

6. In Python, we use `sys.getsizeof()` which includes extra overhead (not just data).
-----------------------------------------------
*/
