#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    cout << "Vector in normal order: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Using reverse iterators
    // rbegin() → points to the last element
    // rend()   → points *before* the first element (not dereferenceable)
    cout << "Vector in reverse order: ";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}