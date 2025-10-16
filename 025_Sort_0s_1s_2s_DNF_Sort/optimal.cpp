#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count0 = 0, count1 = 0, count2 = 0;

        // Count occurrences of 0, 1, and 2
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) count0++;
            else if (nums[i] == 1) count1++;
            else count2++;
        }

        // Overwrite nums array with counted values
        int index = 0;
        for (int i = 0; i < count0; i++) nums[index++] = 0;
        for (int i = 0; i < count1; i++) nums[index++] = 1;
        for (int i = 0; i < count2; i++) nums[index++] = 2;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);

    cout << "Sorted colors: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}