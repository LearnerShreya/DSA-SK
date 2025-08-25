#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = prices[0];   // track minimum price so far

        for (int i = 1; i < prices.size(); i++) {
            // check if selling today gives better profit
            maxProfit = max(maxProfit, prices[i] - bestBuy);

            // update bestBuy (lowest price so far)
            bestBuy = min(bestBuy, prices[i]);
        }

        return maxProfit;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};

    cout << "Example 1: " << sol.maxProfit(prices1) << endl;  // Expected 5
    cout << "Example 2: " << sol.maxProfit(prices2) << endl;  // Expected 0

    return 0;
}


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxProfit = 0;
//         int bestBuy = prices[0];   // lowest price so far

//         for (int i = 1; i < prices.size(); i++) {
//             // check if selling today gives more profit
//             maxProfit = max(maxProfit, prices[i] - bestBuy);

//             // update bestBuy (minimum price till now)
//             bestBuy = min(bestBuy, prices[i]);
//         }

//         return maxProfit;
//     }
// };