#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize vector
    vector<int> vec = {10, 20, 30, 40, 50};

    // Access elements using iterators
    // vec.begin() → returns iterator pointing to first element
    // vec.end()   → returns iterator pointing **past the last element**
    cout << "Vector elements using iterators: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " "; // dereference iterator to get value
    }
    cout << endl;

    // Using auto keyword for iterator (modern C++)
    cout << "Vector elements using auto iterator: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Access first and last elements using iterators
    cout << "First element: " << *vec.begin() << endl;
    cout << "Last element: " << *(vec.end() - 1) << endl; // end() points past last, so -1

    return 0;
}
