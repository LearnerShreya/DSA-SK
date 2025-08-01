
// Qs
// Calculate nCr binomial coefficient for n & r


#include <iostream>
using namespace std;

int fact(int n){
    int i, fact = 1;
    for(i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}

int nCr(int n, int r){
    int fact_n = fact(n);
    int fact_r = fact(r);
    int fact_nmr = fact(n-r);

    return fact_n/(fact_r * fact_nmr);
}

int main() {
    int n =6, r=4;
    cout <<"nCr binomial coefficient for n & r: "<< nCr(n, r) << endl;
    return 0;
}



// #include <iostream>
// using namespace std;

// int binoCoff(int n, int r){

//     // factorial of n
//     int i, facN = 1;
//     for(i=1; i<=n; i++){
//         facN *= i;
//     }
//     cout<<"Factorial (n): "<<facN<<endl;

//     // factorial of r
//     int facR = 1;
//     for(i=1; i<=r; i++){
//         facR *= i;
//     }
//     cout<<"Factorial (r): "<<facR<<endl;

//     // factorial of NR / n-r
//     int facNR = 1;
//     int nr = n-r;
//     for(i=1; i<=nr; i++){
//         facNR *= i;
//     }
//     cout<<"Factorial (n-r): "<<facNR<<endl;
//     return facN/(facR*facNR);
// }


// int main() {
//     cout <<"nCr binomial coefficient for n & r: "<< binoCoff(6, 2) << endl;
//     return 0;
// }
