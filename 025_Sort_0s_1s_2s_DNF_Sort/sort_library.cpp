#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Using STL sort
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