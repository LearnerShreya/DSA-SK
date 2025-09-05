#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a =10;
    int* ptr = &a; // pointer variable ptr is created which points to address of a
    
    int** parPtr = &ptr; // pointer to pointer variable parPtr is created which points to address of ptr
    cout<<&ptr<<endl; // address of ptr
    cout<<parPtr<<endl; // address of ptr (same as above)
}