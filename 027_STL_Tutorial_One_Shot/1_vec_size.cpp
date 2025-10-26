#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vect;
    vector<int> vec = {10, 20, 30, 40};

    cout << "Size of vector (vect): " << vect.size() << endl;
    cout << "Size of vector (vec): " << vec.size() << endl;

    // Example: using size() in a loop
    for (int i = 0; i < vec.size(); i++) {
        cout << "Element " << i << ": " << vec[i] << endl;
    }

    return 0;
}
