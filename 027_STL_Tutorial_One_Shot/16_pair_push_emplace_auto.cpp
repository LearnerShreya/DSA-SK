#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize vector of pairs
    vector<pair<int, int>> vec = {{1, 2}, {2, 3}, {3, 4}};

    // Iterate using explicit pair<int,int>
    cout << "Using pair<int,int>:" << endl;
    for (pair<int, int> p : vec) {
        cout << p.first << " " << p.second << endl;
    }

    // Insert new elements
    vec.push_back({4, 5});       // push_back requires a pair object
    vec.emplace_back(6, 7);      // emplace_back constructs in place

    // Iterate using auto
    cout << "After push_back and emplace_back (using auto):" << endl;
    for (auto p : vec) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}