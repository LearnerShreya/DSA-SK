#include <iostream>
#include <vector>
#include <algorithm> // for next_permutation
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};

    // Get the next permutation using STL
    bool hasNext = next_permutation(nums.begin(), nums.end());

    cout << "Next Permutation: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    if (!hasNext)
        cout << "This was the last permutation, so it is now reset to the first one." << endl;

    return 0;
} 