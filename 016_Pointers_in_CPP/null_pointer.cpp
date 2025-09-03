#include<iostream>
#include<vector>
using namespace std;

int main(){
    int* ptr; // Uninitialized pointer (may point anywhere, dangerous to dereference)
    int* ptr1 = nullptr; // Null pointer (C++11 and later), points to nothing
    int* ptr2 = NULL; // Null pointer (older style), also points to nothing

    cout << ptr << endl;   // Prints the garbage address stored in uninitialized ptr
    cout << ptr1 << endl;  // Prints 0 or nullptr (null pointer value)
    cout << ptr2 << endl;  // Prints 0 or nullptr (null pointer value)

    // The following lines will cause a runtime error (segmentation fault/access violation)
    // because dereferencing a null pointer is undefined behavior.
    cout << *ptr2 << endl; // Dangerous: dereferencing a null pointer
    cout << *(ptr2) << endl; // Same as above

    return 0;
}