#include <iostream>
using namespace std;

// Function definition
int printHello() {
    cout << "hello\n";
    return 3;
}

int main() {
    // Function call / invoke
    printHello();
    int val = printHello();
    cout << "val = " << val << endl;
    cout<<printHello()<< endl;
    return 0;
}
