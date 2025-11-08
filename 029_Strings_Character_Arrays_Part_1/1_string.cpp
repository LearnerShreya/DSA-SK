#include <iostream>
#include <cstring> // for strlen()
using namespace std;

int main() {
    // 1. Character array without '\0'
    char str1[] = {'a', 'b', 'c'};
    cout << "str1 (without null terminator): ";
    cout << str1 << endl;  // may print garbage after "abc"
    
    // 2. Character array with '\0'
    char str2[] = {'a', 'b', 'c', '\0'};
    cout << "str2 (with null terminator): ";
    cout << str2 << endl;  // prints "abc" correctly

    // 3. String literal (automatically ends with '\0')
    char str3[] = "hello";
    cout << "str3 (string literal): " << str3 << endl;
    
    // 4. Integer array (not printable directly like char array)
    int arr[] = {1, 2, 3};
    cout << "arr (base address of array): " << arr << endl; // prints memory address

    // 5. Printing specific elements
    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[1]: " << arr[1] << endl;
    cout << "arr[2]: " << arr[2] << endl;

    // 6. Using strlen() – counts characters until '\0'
    cout << "Length of str3 using strlen(): " << strlen(str3) << endl;

    // 7. Trying to access beyond valid index (unsafe, just for understanding)
    cout << "arr[5] (out of range, undefined behavior): " << arr[5] << endl;

    return 0;
}



// str1 (without null terminator): abc0 a
// str2 (with null terminator): abc
// str3 (string literal): hello
// arr (base address of array): 0x61fef4
// arr[0]: 1
// arr[1]: 2
// arr[2]: 3
// Length of str3 using strlen(): 5
// arr[5] (out of range, undefined behavior): 1667391744