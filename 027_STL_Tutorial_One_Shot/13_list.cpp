#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    l.emplace_back(1);  // emplace_back(1) → 1
    l.push_back(2);     // push_back(2) → 1 2
    l.push_front(3);    // push_front(3) → 3 1 2
    l.push_front(5);    // push_front(5) → 5 3 1 2
    l.pop_back();       // pop_back() → 5 3 1
    l.pop_front();      // pop_front() → 3 1

    // Final Output: 3 1
    for (int val : l) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}