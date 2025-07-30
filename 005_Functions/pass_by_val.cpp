#include <iostream>
using namespace std;

int sum(int a, int b) {
    a = a + 10;  // a = 5 + 10 = 15
    b = b + 10;  // b = 4 + 10 = 14
    cout<<"a: "<<a<<endl;
    return a + b;           // return 15 + 14 = 29 // <-- Function ends here. Anything after this won't run.
    cout<<"b: "<<b;    // ❌ This line is unreachable
}


int main() {
    int a = 5, b = 4;
    cout << sum(a, b) << endl;  // prints 29
    cout <<"a = "<< a << endl;          // prints 5 (original a, not changed)
    cout <<"b = "<< b << endl;          // prints 4 (original b, not changed)
    return 0;
}
