#include <iostream>
using namespace std;

int binToDecimal(int binNum) {
    int ans = 0, pow = 1;
    while(binNum > 0) {
        int rem = binNum % 10;   // Get the last digit (0 or 1)
        ans += rem * pow;        // Add to answer after multiplying by power of 2
        binNum /= 10;            // Remove the last digit
        pow *= 2;                // Move to next power of 2
    }
    return ans;  // Return the final decimal number
}

int main() {
    cout << binToDecimal(101) << endl; // Output: 5
    return 0;
}
