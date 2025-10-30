#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    // vec.front() → returns the first element.
    // vec.back() → returns the last element.
    // vec.begin() → returns an iterator pointing to the first element; dereference with * to access the value.

    cout << "First element (front): " << vec.front() << endl;
    cout << "Last element (back): " << vec.back() << endl;

    // Access first element using iterator from begin()
    cout << "First element using begin(): " << *vec.begin() << endl;

    return 0;
}
