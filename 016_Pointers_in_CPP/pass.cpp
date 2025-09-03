#include <iostream>
using namespace std;

// Pass by value (copy)
void changeByValue(int a) {
    a = 20;
}

// Pass by reference (alias)
void changeByReference(int &a) {
    a = 30;
}

// Pass by pointer
void changeByPointer(int *a) {
    *a = 40;
}

int main() {
    int a = 10;
    cout << "Initially a = " << a << endl;

    changeByValue(a);
    cout << "After changeByValue, a = " << a << endl; // still 10

    changeByReference(a);
    cout << "After changeByReference, a = " << a << endl; // now 30

    changeByPointer(&a);
    cout << "After changeByPointer, a = " << a << endl; // now 40

    return 0;
}
