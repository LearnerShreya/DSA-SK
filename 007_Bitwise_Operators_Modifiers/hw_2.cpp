
// WAF to reverse an Integer n.

#include <iostream>
using namespace std;

int reverseNumber(int n) {
    int rev = 0;
    while (n != 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }
    return rev;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int reversed = reverseNumber(n);
    cout << "Reversed Number: " << reversed << endl;

    return 0;
}