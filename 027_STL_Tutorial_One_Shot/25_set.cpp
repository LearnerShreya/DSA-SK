#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // inserting elements
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    // printing elements (automatically sorted in ascending order)
    cout << "Elements in set: ";
    for (auto val : s) {
        cout << val << " ";
    }
    cout << endl;
    cout<<"Size of set s: "<<s.size()<<endl;

    return 0;
}


// Output:
// Elements in set: 1 2 3 4 5
// Size of set s: 5