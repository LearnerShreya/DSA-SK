#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Corrected: closing bracket was ) instead of }
    vector<int> vec = {1, 2, 3, 4, 5};

    // Declare iterator
    vector<int>::iterator it;

    // Iterate through vector using iterator
    for (it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " "; // dereference iterator to get value
    }
    cout << endl;

    return 0;
}