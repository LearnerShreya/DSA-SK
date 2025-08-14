#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n = 7;
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};

    int maxSum = INT_MIN;

        for(int st = 0; st<n; st++){
            int curSum = 0;
            for(int end = st; end<n; end++){
                curSum += arr[end];
                maxSum = max(curSum, maxSum);
        }
    }
    cout<<"Max sum: "<<maxSum;
    return 0;
}