#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    cout << "Original vector: ";
    for (auto val : vec) cout << val << " ";
    cout << "\n";

    // 1. Reverse the whole vector
    reverse(vec.begin(), vec.end());
    cout << "Reversed vector: ";
    for (auto val : vec) cout << val << " ";
    cout << "\n";

    // 2. Reverse a specific range (2nd to 4th element)
    reverse(vec.begin() + 1, vec.begin() + 4);
    cout << "After reversing range [1,4): ";
    for (auto val : vec) cout << val << " ";
    cout << "\n";

    // Reset to ascending for permutation examples
    vec = {1, 2, 3};

    cout << "\nCurrent vector: ";
    for (auto val : vec) cout << val << " ";
    cout << "\n";

    // 3. Next permutation
    if (next_permutation(vec.begin(), vec.end())) {
        cout << "Next permutation: ";
        for (auto val : vec) cout << val << " ";
        cout << "\n";
    } else {
        cout << "No next permutation (it was last one)\n";
    }

    // 4. Previous permutation
    if (prev_permutation(vec.begin(), vec.end())) {
        cout << "Previous permutation: ";
        for (auto val : vec) cout << val << " ";
        cout << "\n";
    } else {
        cout << "No previous permutation (it was first one)\n";
    }

    return 0;
}
