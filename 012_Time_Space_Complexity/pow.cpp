#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;      // use long long to handle -2^31
        if (power < 0) {          // if n is negative
            x = 1 / x;            // take reciprocal
            power = -power;       // make power positive
        }

        double ans = 1.0;
        while (power > 0) {
            if (power % 2 == 1) { // if current bit is 1
                ans *= x;
            }
            x *= x;               // square the base
            power /= 2;           // shift right
        }

        return ans;
    }
};

// Driver code
int main() {
    Solution sol;

    cout << fixed << setprecision(5);

    cout << "Example 1: " << sol.myPow(2, 10) << endl;     // 1024.00000
    cout << "Example 2: " << sol.myPow(2.1, 3) << endl;    // 9.26100
    cout << "Example 3: " << sol.myPow(2, -2) << endl;     // 0.25000

    return 0;
}




// class Solution {
// public:
//     double myPow(double x, int n) {
//         // Base cases
//         if (n == 0) return 1.0;
//         if (x == 0) return 0.0;
//         if (x == 1) return 1.0;
//         if (x == -1) return (n % 2 == 0) ? 1.0 : -1.0;

//         long long binForm = n;   // ✅ use long long for safety

//         if (binForm < 0) {       // handle negative exponent
//             x = 1 / x;
//             binForm = -binForm;
//         }

//         double ans = 1.0;
//         while (binForm > 0) {
//             if (binForm % 2 == 1) {
//                 ans *= x;
//             }
//             x *= x;
//             binForm /= 2;
//         }
//         return ans;
//     }
// };