#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int pivot = -1;

        // Step 1: find the pivot
        for (int i = n - 2; i >= 0; i--) { // n-2 because we check A[i] < A[i+1]
            if (A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot found, reverse the array
        if (pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 2: find the next larger element to swap with pivot
        for (int i = n - 1; i > pivot; i--) {
            if (A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 3: reverse the elements after pivot
        int i = pivot + 1, j = n - 1;
        while (i < j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    
    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}