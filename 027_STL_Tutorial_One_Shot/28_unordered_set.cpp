#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    cout << "Unordered set elements: ";
    for (auto val : s) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

// // Output:
// Unordered set elements: 3 1 4 2 5