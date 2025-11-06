#include <iostream>
#include <vector>
#include <algorithm>  // for max_element, min_element, binary_search
using namespace std;

int main() {
    vector<int> v = {3, 7, 2, 9, 5, 9, 1};

    cout << "Vector elements: ";
    for (int val : v) cout << val << " ";
    cout << "\n\n";

    // 1. Max and Min Element
    auto maxIt = max_element(v.begin(), v.end());
    auto minIt = min_element(v.begin(), v.end());
    cout << "Max element: " << *maxIt << endl;
    cout << "Min element: " << *minIt << endl;

    // 2. Binary Search (vector must be sorted)
    sort(v.begin(), v.end());
    cout << "\nSorted vector: ";
    for (int val : v) cout << val << " ";
    cout << endl;

    int target = 5;
    bool found = binary_search(v.begin(), v.end(), target);
    cout << "Binary search for " << target << ": "
         << (found ? "Found" : "Not found") << endl;

    // 3. Count set bits in integer

// __builtin_popcount(n)	Counts number of 1-bits in an int
// __builtin_popcountl(n)	Same for long
// __builtin_popcountll(n)	Same for long long

    int num = 29; // binary 11101 -> 4 set bits
    cout << "\nNumber: " << num << endl;
    cout << "__builtin_popcount(num): " << __builtin_popcount(num) << endl;
    cout << "__builtin_popcountl(num): " << __builtin_popcountl(num) << endl;
    cout << "__builtin_popcountll(num): " << __builtin_popcountll(num) << endl;

    return 0;
}


// Vector elements: 3 7 2 9 5 9 1 

// Max element: 9
// Min element: 1

// Sorted vector: 1 2 3 5 7 9 9
// Binary search for 5: Found

// Number: 29
// __builtin_popcount(num): 4
// __builtin_popcountl(num): 4
// __builtin_popcountll(num): 4
