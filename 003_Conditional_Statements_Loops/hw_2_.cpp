// Homework
// Qs. Sum of all numbers from 1 to N which are divisible by 3.
// Qs. Print Factorial of a number N.

#include <iostream>
using namespace std;

int main(){
    int n, fac=1;
    cout<<"Enter num: ";
    cin>>n;

    for(int i=1; i<=n; i++){
        fac *= i;
    }
    cout<<"Sum of numbers from 1 to "<<n<<" = "<<fac;
}