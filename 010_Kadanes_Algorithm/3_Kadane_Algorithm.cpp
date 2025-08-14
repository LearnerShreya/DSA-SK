#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, maxSum = INT_MIN;

        for (int val : nums) {
            curSum += val;
            maxSum = max(curSum, maxSum);

            if (curSum < 0) {
                curSum = 0;
            }
        }
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = sol.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
}