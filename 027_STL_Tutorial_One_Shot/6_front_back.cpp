#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    cout << "First element (front): " << vec.front() << endl;
    cout << "Last element (back): " << vec.back() << endl;

    return 0;
}