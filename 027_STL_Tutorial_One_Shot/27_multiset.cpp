#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    cout << "Multiset elements: ";
    for (auto val : s) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}



// // Output:
// Multiset elements: 1 1 2 2 3 3 4 5