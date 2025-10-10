#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        if (n == 1) return A[0];

        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;  // correct mid calculation

            // Check if mid is the single element
            if ((mid == 0 && A[0] != A[1]) || 
                (mid == n - 1 && A[n - 1] != A[n - 2]) || 
                (mid > 0 && mid < n - 1 && A[mid] != A[mid - 1] && A[mid] != A[mid + 1])) {
                return A[mid];
            }

            // Binary search logic based on index parity
            if (mid % 2 == 0) { // even
                if (A[mid] == A[mid - 1]) { // left
                    end = mid - 1;
                } else { // right
                    st = mid + 1;
                }
            } else { // odd
                if (A[mid] == A[mid - 1]) { // right
                    st = mid + 1;
                } else { // left
                    end = mid - 1;
                }
            }
        }

        return -1; // single element not found (edge case)
    }
};

int main() {
    Solution sol;

    // Test case: single element is 2
    vector<int> arr = {1,1,2,3,3,4,4,5,5};

    int result = sol.singleNonDuplicate(arr);
    cout << "The single non-duplicate element is: " << result << endl;

    return 0;
}