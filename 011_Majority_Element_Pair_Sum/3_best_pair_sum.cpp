#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target) {
    vector<int> ans;
    int n = nums.size();

    int i = 0, j = n - 1;
    while (i < j) {
        int sum = nums[i] + nums[j];
        
        if (sum > target) {
            j--;
        } else if (sum < target) {
            i++;
        } else {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    
    // No pair found
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6}; // This should be sorted for two-pointer
    int target = 9;

    vector<int> ans = pairSum(nums, target);
    if (ans.size() == 2)
        cout << ans[0] << ", " << ans[1] << endl;
    else
        cout << "No pair found" << endl;

    return 0;
}