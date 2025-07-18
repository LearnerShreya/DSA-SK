#include <iostream>  // Header for input-output operations
using namespace std;

int main() {
    int a = 10;
    int b = a++;
    cout<<"b = "<<b<<endl;
    cout<<"a = "<<a<<endl;
    int c = ++a;
    cout<<"c = "<<c<<endl;
    int d = --a;
    cout<<"d = "<<d<<endl;

    return 0;
}