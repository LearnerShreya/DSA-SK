#include <iostream>
#include <vector>
using namespace std;

// Recursive Binary Search
int recBinarySearch(vector<int> arr, int tar, int st, int end) {
    if (st <= end) {
        int mid = st + (end - st) / 2;  // avoid overflow

        if (tar > arr[mid]) {  // search in right half
            return recBinarySearch(arr, tar, mid + 1, end);
        } 
        else if (tar < arr[mid]) {  // search in left half
            return recBinarySearch(arr, tar, st, mid - 1);
        } 
        else {  // found
            return mid;
        }
    }
    return -1;  // not found
}

int main() {
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    int tar1 = 40;
    cout << "Index of " << tar1 << " = " 
         << recBinarySearch(arr1, tar1, 0, arr1.size() - 1) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    int tar2 = 0;
    cout << "Index of " << tar2 << " = " 
         << recBinarySearch(arr2, tar2, 0, arr2.size() - 1) << endl;

    return 0;
}