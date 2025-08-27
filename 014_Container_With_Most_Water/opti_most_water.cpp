// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxWater = 0; 
//         int lp = 0, rp = height.size() - 1; 

//         while (lp < rp) {
//             int w = rp - lp; 
//             int ht = min(height[lp], height[rp]); 
//             int currWater = w * ht; 
//             maxWater = max(maxWater, currWater);

//             // Move the smaller height pointer using ternary operator
//             (height[lp] < height[rp]) ? lp++ : rp--;
//         }

//         return maxWater;
//     }
// };


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0; 
        int lp = 0, rp = height.size() - 1; 

        while (lp < rp) {
            int w = rp - lp; 
            int ht = min(height[lp], height[rp]); 
            int currWater = w * ht; 
            maxWater = max(maxWater, currWater);

            // Move the smaller height pointer using ternary operator
            (height[lp] < height[rp]) ? lp++ : rp--;
        }

        return maxWater;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution obj;
    cout << "Maximum water: " << obj.maxArea(height) << endl;
    return 0;
}