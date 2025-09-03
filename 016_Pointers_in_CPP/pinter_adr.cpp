#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a = 5;
    int* p = &a;
    int** q = &p;

    cout << p << endl;
    cout << *q << endl; // &a
    cout << &a << endl;

    cout << *p << endl;
    cout << **q << endl; 

    return 0;
}