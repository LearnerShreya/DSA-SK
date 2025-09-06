#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a =10;
    int* ptr = &a; // pointer variable ptr is created which points to address of a
    cout<<"The value of a is: "<<a<<endl;
    cout<<"The value of a using pointer is: "<<*ptr<<endl;
    cout<<"The value of ptr is: "<<ptr<<endl;
    cout<<"The address of a is: "<<&a<<endl;
    cout<<"The address of ptr is: "<<&ptr<<endl;
    cout<<"The size of a is: "<<sizeof(a)<<endl;
}