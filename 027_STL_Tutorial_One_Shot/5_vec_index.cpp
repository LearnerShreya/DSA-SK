#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec; // initially empty

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.emplace_back(6); // adds 6 at the end
    vec.pop_back();      // removes last element (6)

    // Print all elements
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // Access element at index 2 (third element)
    // vec[2] → directly accesses the 3rd element (faster, no bounds check)
    // vec.at(2) → accesses index 2 but throws an error if index is invalid (safer)
    cout << "Value at index 2: " << vec[2] << " or " << vec.at(2) << endl;

    return 0;
}