
// Figure out how to find if a number is power of 2 without any loop.

// (n & (n - 1)) == 0  → Power of 2

#include <iostream>
using namespace std;

bool isPowerOf2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOf2(n))
        cout << n << " is a power of 2." << endl;
    else
        cout << n << " is NOT a power of 2." << endl;

    return 0;
}