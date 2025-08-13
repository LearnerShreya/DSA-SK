#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Different ways to create a vector
    vector<int> v1;                       // Empty vector
    vector<int> v2(5);                    // Vector of size 5 with default values (0)
    vector<int> v3(5, 10);                // Vector of size 5 with all values = 10
    vector<int> v4 = {1, 2, 3, 4};        // Initialization using initializer list
    vector<int> v5(v4);                   // Copy constructor

    // Print elements of v5
    for (int i = 0; i < v5.size(); i++) {
        cout << v5[i] << " ";
    }
    cout << endl;
    // Print elements of v4
    for (int i = 0; i < v4.size(); i++) {
        cout << v4[i] << " ";
    }
    cout << endl;
    // Print elements of v3
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;
    // Print elements of v2
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
    // Print elements of v1
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    return 0;
}