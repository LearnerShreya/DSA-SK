
#include <iostream>
using namespace std;

// Function that modifies the original variable using reference
int changeValue(int &a, int b) {
    a = 50;  // This WILL change the original variable in main()
    return a + b;
}

int main() {
    int original = 10;
    int result = changeValue(original, 20);

    cout << "Result of function: " << result << endl;       // Outputs: 70
    cout << "Original value after function: " << original;  // Outputs: 50 (changed)

    return 0;
}
