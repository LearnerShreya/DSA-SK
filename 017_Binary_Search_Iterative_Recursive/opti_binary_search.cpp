#include <iostream>
#include <vector>
using namespace std;

// Iterative Binary Search (prevents integer overflow)
int binarySearch(vector<int> arr, int tar) {
    int st = 0, end = arr.size() - 1;
    
    while (st <= end) {
        int mid = st + (end - st) / 2;  // ✅ safer mid calculation
        
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
    // Case 1: Odd-sized array (target present)
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; 
    int tar1 = 12;
    cout << "Odd-sized array → Index of " << tar1 << " = " << binarySearch(arr1, tar1) << endl;

    // Case 2: Even-sized array (target present)
    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; 
    int tar2 = 0;
    cout << "Even-sized array → Index of " << tar2 << " = " << binarySearch(arr2, tar2) << endl;

    // Case 3: Target not found (-1 case)
    vector<int> arr3 = {2, 4, 6, 8, 10};
    int tar3 = 7;
    cout << "Target not found → Index of " << tar3 << " = " << binarySearch(arr3, tar3) << endl;

    return 0;
}