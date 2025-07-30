#include <iostream>
using namespace std;

// Function to find sum of 2 numbers
int sum(int a, int b) {
    int s = a + b; 
    return s;
}


// min of 2 numbers
int min(int n1, int n2){
    if(n1<n2){
        return n1;
    } else{
        return n2;
    }
}


int main() {

    cout<<"Sum: "<<sum(5,5)<<endl;
    cout<<"Min value: "<<min(5,1)<<endl;

    int result = sum(10, 5); 
    cout << "Sum = " << result << endl; 

    return 0;
}
