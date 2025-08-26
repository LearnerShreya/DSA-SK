// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxProfit = 0;               // best profit so far
//         int bestBuy = prices[0];         // lowest price so far (best day to buy)

//         for (int i = 1; i < prices.size(); i++) {
//             // If we sell today, what profit do we get?
//             maxProfit = max(maxProfit, prices[i] - bestBuy);

//             // Update bestBuy if today’s price is lower
//             bestBuy = min(bestBuy, prices[i]);
//         }

//         return maxProfit;
//     }
// };





#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;               // best profit we can get
        int bestBuy = prices[0];         // lowest price seen so far (best day to buy)

        for (int i = 1; i < prices.size(); i++) {
            // If we sell today, calculate profit
            maxProfit = max(maxProfit, prices[i] - bestBuy);

            // Update bestBuy if today’s price is lower
            bestBuy = min(bestBuy, prices[i]);
        }

        return maxProfit; // final answer
    }
};

int main() {
    // Example input
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Create object of Solution
    Solution sol;

    // Function call
    int result = sol.maxProfit(prices);

    // Print result
    cout << "Maximum Profit: " << result << endl;

    return 0;
}