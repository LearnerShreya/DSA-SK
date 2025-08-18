#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;

    // Step 1: Find a potential candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Step 2: Verify the candidate
    int freq = 0;
    for (int num : nums) {
        if (num == candidate) freq++;
    }

    // Step 3: Return result
    return (freq > nums.size() / 2) ? candidate : -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityElement(nums);

    if (result != -1) {
        cout << "Majority Element: " << result << endl;
    } else {
        cout << "No majority element found" << endl;
    }

    return 0;
}



// int majorityElement(vector<int>& nums) {
//     int n = nums.size();
//     for (int val : nums) {
//         int freq = 0;
//         for (int el : nums) {
//             if (el == val) {
//                 freq++;
//             }
//         }
//         if (freq > n / 2) {
//             return val;
//         }
//     }
//     return -1; // In case no majority element exists
// }