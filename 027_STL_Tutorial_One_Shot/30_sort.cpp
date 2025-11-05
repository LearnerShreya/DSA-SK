#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 1. Sorting vector in ascending and descending order
    vector<int> vec = {3, 5, 1, 8, 2};

    cout << "Original vector: ";
    for (int val : vec) cout << val << " ";
    cout << "\n";

    // Ascending order
    sort(vec.begin(), vec.end());
    cout << "Ascending order: ";
    for (int val : vec) cout << val << " ";
    cout << "\n";

    // Descending order
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "Descending order: ";
    for (int val : vec) cout << val << " ";
    cout << "\n\n";

    // 2. Sorting vector of pairs
    vector<pair<int, int>> vp = {
        {3, 5}, {1, 9}, {3, 2}, {2, 7}, {1, 4}
    };

    cout << "Original pairs:\n";
    for (auto p : vp)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << "\n";

    // Sort by first, then by second (ascending)
    sort(vp.begin(), vp.end());
    cout << "Pairs sorted ascending by first then second:\n";
    for (auto p : vp)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << "\n";

    // Sort by first ascending, second descending
    sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second > b.second;  // second descending
        return a.first < b.first;        // first ascending
    });

    cout << "Pairs sorted by first asc & second desc:\n";
    for (auto p : vp)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << "\n";

    return 0;
}



// // Output:
// Original vector: 3 5 1 8 2 
// Ascending order: 1 2 3 5 8 
// Descending order: 8 5 3 2 1 

// Original pairs:
// (3, 5) (1, 9) (3, 2) (2, 7) (1, 4) 
// Pairs sorted ascending by first then second:
// (1, 4) (1, 9) (2, 7) (3, 2) (3, 5) 
// Pairs sorted by first asc & second desc:
// (1, 9) (1, 4) (2, 7) (3, 5) (3, 2)