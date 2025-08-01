
// Qs
// Calculate sum of digits of a number.

#include <iostream>
using namespace std;

int sumOfDigits(int num) {
    int digSum = 0;
    while(num>0){
        int lastDig = num%10;
        num /= 10;
        digSum += lastDig;
    }
    return digSum;
}


int main() {
    cout <<"Sum: "<< sumOfDigits(12345) << endl;
    return 0;
}
