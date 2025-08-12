#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int val : nums){
            ans ^= val;  // XOR operation
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 3, 2, 4, 3};
    int unique = obj.singleNumber(nums);
    cout << "The unique number is: " << unique << endl;

    return 0;
}