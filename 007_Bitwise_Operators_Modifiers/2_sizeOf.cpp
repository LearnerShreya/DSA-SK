#include <iostream>
using namespace std;

int main() {
    // Size demonstration of different modifiers
    cout << "Size of short: " << sizeof(short) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;
    
    cout << "Size of signed int: " << sizeof(signed int) << " bytes" << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;

    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;

    return 0;
}


// Size of short: 2 bytes
// Size of int: 4 bytes
// Size of long: 8 bytes
// Size of long long: 8 bytes
// Size of signed int: 4 bytes
// Size of unsigned int: 4 bytes
// Size of float: 4 bytes
// Size of double: 8 bytes
// Size of long double: 16 bytes