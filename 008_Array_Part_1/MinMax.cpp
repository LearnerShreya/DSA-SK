#include<iostream>
#include <climits>
using namespace std;

int main(){
    int arr[5] = {20, -47, 52, 59, -12};
    int size = 5;
    int smaller = INT_MAX;
    int index = -1;
    for(int i=0; i<size; i++){
        // if (arr[i] < smaller)
        // smaller = arr[i];
        smaller = min(arr[i], smaller);
    }
    cout<<smaller<<endl;

    int larger = INT_MIN;
    for(int i=0; i<size; i++){
        if (arr[i] > larger){
            larger = arr[i];
            index = i;
        }
        
        // larger = max(larger, arr[i]);
    }
    cout<<larger<<endl;
    cout<<index;

    return 0;
}