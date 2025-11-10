#include <iostream>
using namespace std;

int main() {
    char str[] = "apna college";
    int len = 0;

    // Loop to count length manually
    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }

    cout << "Length of string: " << len << endl;
    return 0;
}

// Length of string: 12