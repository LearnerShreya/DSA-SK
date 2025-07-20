// Square Pattern
// Easy with numbers n = 4
// 1 2 3 4 
// 1 2 3 4 
// 1 2 3 4 
// 1 2 3 4 

#include <iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;

    // for(int i=1; i<=n; i++){
    // for(int j=1; j<=n; j++)
    // cout<<j<<" ";
    // cout<<endl;
    // }

    for(int i=0; i<n; i++){
        char ch = 'a';
        for(int j=0; j<n; j++){
            cout<<ch<<" ";
            ch += 1;
        }
        cout<<endl;
    }
    return 0;
}