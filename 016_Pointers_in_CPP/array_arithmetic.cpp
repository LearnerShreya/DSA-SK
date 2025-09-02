#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    // Demonstrating pointer arithmetic with arrays
    cout << *arr << endl;         // same as arr[0] → 1
    cout << *(arr + 0) << endl;   // same as arr[0] → 1
    cout << *(arr + 1) << endl;   // same as arr[1] → 2
    cout << *(arr + 2) << endl;   // same as arr[2] → 3

    int* ptr1 = arr;        // points to first element (arr[0])
    int* ptr2 = arr + 2;    // points to third element (arr[2])

    // Pointer arithmetic
    cout << (ptr2 - ptr1) << endl;         // Difference in elements (should be 2)
    cout << *ptr2 << endl;                 // Value at ptr2 (should be 3)
    cout << (ptr1 < ptr2) << endl;         // 1 (true), ptr1 points before ptr2
    cout << (ptr1 != ptr2) << endl;        // 1 (true), pointers are not equal



    cout << "ptr1 (arr[0] address): " << ptr1 << endl;
    cout << "ptr2 (arr[1] address): " << ptr2 << endl;

    cout << "(ptr1 != ptr2) : " << (ptr1 != ptr2) << endl; // 1 (true)
    cout << "(ptr1 == ptr2) : " << (ptr1 == ptr2) << endl; // 0 (false)

    return 0;