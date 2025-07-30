/* // Function : reusability, readibility

#include<iostream>
using namespace std;

int Sum(int m, int n)      // Function declare
{     
    int ans = m+n;         // Function define
    return ans;
}

int Mul(int m, int n) {     
    int ans = m*n;         
    return ans;
}

int main(){
    int a,b;
    cout<<"Enter 2 number: ";
    cin>>a>>b;

    // function call
    cout<<"Sum of number is: "<<Sum(a, b);
    // int ans = Sum(a,b);
    // cout<<ans;
    cout<<endl;
    cout<<"Multiplication of number is: "<<Mul(a,b);

} */





#include<iostream>
using namespace std;

void Sum(int m, int n)      // Function declare
{     
    int ans = m+n;         // Function define
    cout<<"Addition is: "<<ans<<endl;
}

int Mul(int m, int n) {     
    int ans = m*n;         
    return ans;
}

int main()
{
    int a,b;
    cout<<"Enter 2 number: ";
    cin>>a>>b;

    // function call
    Sum(a, b);
    cout<<"Multiplication is: "<<Mul(a,b);

}