#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;

    vec.push_back(10);
    vec.emplace_back(20);
    vec.emplace_back(30);

    cout << "Elements in vector: ";
    for (int val : vec)
        cout << val << " ";

    cout << endl;
    cout << "Size of vector: " << vec.size() << endl;

    return 0;
}