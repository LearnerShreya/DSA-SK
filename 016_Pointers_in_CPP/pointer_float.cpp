#include<iostream>
#include<vector>
using namespace std;

int main(){
    float price = 100.25;
    float* ptr = &price; // pointer variable ptr is created which points to address of price
    cout<<"The value of price is: "<<price<<endl;
    cout<<"The value of price using pointer is: "<<*ptr<<endl;
    cout<<"The value of ptr is: "<<ptr<<endl;
    cout<<"The address of price is: "<<&price<<endl;
    cout<<"The address of ptr is: "<<&ptr<<endl;
    cout<<"The size of price is: "<<sizeof(price)<<endl;
}