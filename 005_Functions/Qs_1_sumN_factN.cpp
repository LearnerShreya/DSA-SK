// Qs
// Calculate sum of numbers from 1 to N.

#include <iostream>
using namespace std;

int sumN(int n) {
    int sum = 0;

    for(int i=1; i<=n; i++){
    sum+=i;
    }
    return sum;
}

int facN(int n) {
    
    if(n==1){
        return 1;
    }
    return n * facN(n-1);
    
    // int fac = 1;
    // for(int i=1; i<=n; i++){
    // fac*=i;
    // }
    // return fac;
    
}
int main() {
    cout << sumN(5)<<endl;
    cout << sumN(10)<<endl;
    cout << facN(5)<<endl;
    cout << facN(10)<<endl;
    return 0;
}
