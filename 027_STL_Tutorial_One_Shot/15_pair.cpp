#include <iostream>
#include <string>
using namespace std;

int main() {
    // Pair of two integers
    pair<int, int> p1 = {1, 5};

    // Pair of string and integer
    pair<string, int> p2 = {"Shreya", 5};

    // Nested pair: int and pair of two ints
    pair<int, pair<int, int>> p3 = {1, {4, 5}};

    // Nested pair: int and pair of char and int
    pair<int, pair<char, int>> p4 = {10, {'A', 100}};

    // Print pairs
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;
    cout << p3.first << " " << p3.second.first << " " << p3.second.second << endl;
    cout << p4.first << " " << p4.second.first << " " << p4.second.second << endl;

    return 0;
}