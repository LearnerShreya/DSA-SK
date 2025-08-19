// #include <iostream>
// #include <vector>
// using namespace std;

// int majorityElement(vector<int>& nums) {
//     int count = 0, candidate = 0;

//     // Step 1: Find a potential candidate
//     for (int num : nums) {
//         if (count == 0) {
//             candidate = num;
//         }
//         count += (num == candidate) ? 1 : -1;
//     }

//     // Step 2: Verify the candidate
//     int freq = 0;
//     for (int num : nums) {
//         if (num == candidate) freq++;
//     }

//     // Step 3: Return result
//     return (freq > nums.size() / 2) ? candidate : -1;
// }

// int main() {
//     vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
//     int result = majorityElement(nums);

//     if (result != -1) {
//         cout << "Majority Element: " << result << endl;
//     } else {
//         cout << "No majority element found" << endl;
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;

        // Step 1: Find candidate
        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                ans = nums[i];
            }
            if (ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }
        }

        // Step 2: Verify if ans is majority
        int count = 0;
        for (int num : nums) {
            if (num == ans) count++;
        }

        // Step 3: Return majority or -1 if not found
        if (count > nums.size() / 2) {
            return ans;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    Solution obj;
    int result = obj.majorityElement(nums);

    if (result != -1) {
        cout << "Majority Element: " << result << endl;
    } else {
        cout << "No majority element found" << endl;
    }

    return 0;
}