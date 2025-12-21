#include <iostream>
using namespace std;

string isPrime(int n) {
    if (n <= 1)
        return "Non prime";

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return "Non prime";
        }
    }
    return "Prime";
}

int main() {
    int n = 42;
    cout << isPrime(n) << endl;
    return 0;
}


// #include<iostream>
// using namespace std;

// int main(){
//     int n = 11;
//     if (n < 2) {
//         cout << "Not Prime";
//         return 0;
//     }
//     // for(int i=2; i<=n/2; i++){
//     for (int i = 2; i * i <= n; i++) {
//     if (n % i == 0) {
//         cout << "Not Prime";
//         return 0;
//     }
// }
// cout << "Prime";
// }