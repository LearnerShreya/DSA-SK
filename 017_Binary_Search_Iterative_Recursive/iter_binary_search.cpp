#include <iostream>
#include <vector>
using namespace std;

// Iterative Binary Search
int binarySearch(vector<int> arr, int tar) {
    int st = 0, end = arr.size() - 1;
    
    while (st <= end) {
        int mid = (st + end) / 2;
        
        if (tar > arr[mid]) {
            st = mid + 1;
        } else if (tar < arr[mid]) {
            end = mid - 1;
        } else {
            return mid;  // Target found
        }
    }
    return -1;  // Target not found
}

int main() {
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd size
    int tar1 = 12;
    cout << "Index of " << tar1 << " = " << binarySearch(arr1, tar1) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even size
    int tar2 = 0;
    cout << "Index of " << tar2 << " = " << binarySearch(arr2, tar2) << endl;

    return 0;
}