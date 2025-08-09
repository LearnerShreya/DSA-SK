#include<iostream>
using namespace std;

int main() {
    // 1. Static array
    int arr[] = {10, 20, 30, 40, 50};

    // Total size in bytes
    cout << "Total size of array in bytes: " << sizeof(arr) << endl;

    // Size of one element
    cout << "Size of one element: " << sizeof(arr[0]) << endl;

    // Number of elements
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of elements in array: " << size << endl;

    // Output using loop
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 2. Dynamic array (using pointers)
    int n;
    cout << "\nEnter size for dynamic array: ";
    cin >> n;

    int* dynArr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> dynArr[i];
    }

    cout << "Dynamic array elements: ";
    for (int i = 0; i < n; i++) {
        cout << dynArr[i] << " ";
    }
    cout << "\nNumber of elements: " << n << endl;

    // sizeof won't work correctly for dynamic array
    cout << "sizeof(dynArr): " << sizeof(dynArr) << " (pointer size, not array size)\n";

    delete[] dynArr;
    return 0;
}