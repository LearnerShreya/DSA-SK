#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();

    // Step 1: Sort the array
    sort(nums.begin(), nums.end());

    // Step 2: Count frequency
    int freq = 1;
    int ans = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            freq++;
        } else {
            freq = 1;
            ans = nums[i];
        }

        // Check if current number is majority
        if (freq > n / 2) {
            return nums[i];
        }
    }

    // If no majority element found
    // (condition) ? value_if_true : value_if_false;
    return (freq > n / 2) ? ans : -1;
}

int main() {
    vector<int> nums = {2, 1, 1, 1, 2, 2};
    // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityElement(nums);

    if (result != -1) {
        cout << "Majority Element: " << result << endl;
    } else {
        cout << "No majority element found" << endl;
    }

    return 0;
}
