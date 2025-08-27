// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxWater = 0; // final answer

//         for(int i = 0; i < height.size(); i++) {
//             for(int j = i + 1; j < height.size(); j++) {
//                 int w = j - i;  // width
//                 int ht = min(height[i], height[j]); // height of container
//                 int currWater = w * ht; // area of water
//                 maxWater = max(maxWater, currWater);
//             }
//         }

//         return maxWater;
//     }
// };




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0; // final answer

        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int w = j - i; // width
                int ht = min(height[i], height[j]); // height of container
                int currWater = w * ht; // area
                maxWater = max(maxWater, currWater);
            }
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