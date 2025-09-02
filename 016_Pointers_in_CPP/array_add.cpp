#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int a = 15;

    // arr = &a; ❌ Not allowed, arr is not assignable

    cout << "First element of arr: " << arr[0] << endl;
    cout << "Address of arr: " << arr << endl;
    cout << "Value of a: " << a << endl;

    return 0;
}