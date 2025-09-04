#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int a = 10;

    int* ptr = &a;
    cout << "Address before increment: " << ptr << endl;

    ptr++; // moves to the next int location
    cout << "Address after increment : " << ptr << endl;

    ptr = ptr + 2;
    cout << ptr << endl;

    return 0;
}