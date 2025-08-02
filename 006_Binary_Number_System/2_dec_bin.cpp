#include <iostream>
using namespace std;

int decToBinary(int decNum) {
    int ans = 0, pow = 1;
    while(decNum > 0) {
        int rem = decNum % 2;    // Get remainder (0 or 1)
        decNum /= 2;             // Divide number by 2
        ans += rem * pow;        // Place digit at correct place (units, tens, hundreds)
        pow *= 10;               // Move to next position (binary digits go right to left)
    }
    return ans; // Binary in integer form
}


int main() {
    int decNum = 50;
    cout << decToBinary(decNum) << endl; // Output: 110010

    decNum = 20;  // Just assign a new value (don't use `int` again)
    cout << decToBinary(decNum) << endl; // Output: 10100

    return 0;
}
