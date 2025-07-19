// Homework
// Qs. Sum of all numbers from 1 to N which are divisible by 3.
// Qs. Print Factorial of a number N.

#include <iostream>
using namespace std;

int main(){
    int n, sum=0;
    cout<<"Enter num: ";
    cin>>n;

    for(int i=1; i<=n; i++){
        if (i%3==0)
        sum += i;
    }
    cout<<"Sum of numbers from 1 to "<<n<<" = "<<sum;
}