#include <iostream>
using namespace std;

// Function that takes two integers
int changeValue(int a, int b) {
    a = 50;  // Only local copy 'a' is changed; original variable in main remains the same
    return a + b;
}

int main() {
    int original = 10;
    int result = changeValue(original, 20);

    cout << "Result of function: " << result << endl;       // Outputs: 70
    cout << "Original value after function: " << original;  // Outputs: 10 (unchanged)

    return 0;
}


