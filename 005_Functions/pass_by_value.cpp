#include <iostream>
using namespace std;

void changeValue(int x) {
    x = 50;  // Change will NOT affect original variable
}

int main() {
    int num = 10;
    changeValue(num);
    cout << "Value after function: " << num;  // Output: 10
    return 0;
}
