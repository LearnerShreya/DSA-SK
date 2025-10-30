#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;  // initially empty

    cout << "Initial size: " << vec.size() << endl;

    // Adding elements
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    cout << "After adding 3 elements: " << vec.size() << endl;

    // Add more
    vec.push_back(4);
    vec.push_back(5);
    cout << "After adding 5 elements: " << vec.size() << endl;

    // Print all elements
    cout << "Elements in vector: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // Remove last element
    vec.pop_back();
    cout << "After pop_back(): " << vec.size() << endl;

    // Print again
    cout << "Elements after removal: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}