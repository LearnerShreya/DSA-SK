#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a = 4, b = 5;
    int x = 6, y = 10;

    // max and min
    cout << "Max of 4 and 5: " << max(a, b) << endl;
    cout << "Min of 6 and 10: " << min(x, y) << endl;

    // swap example
    cout << "\nBefore swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0;
}


// Max of 4 and 5: 5
// Min of 6 and 10: 6

// Before swap: a = 4, b = 5
// After swap: a = 5, b = 4