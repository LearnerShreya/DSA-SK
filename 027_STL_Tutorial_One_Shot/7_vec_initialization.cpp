#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec1;               // empty
    vector<int> vec2 = {1, 2};      // initializer list
    vector<int> vec3(3, 10);        // size 3, all 10
    vector<int> vec4(vec2);         // copy of vec2

    cout << "vec2: ";
    for (int v : vec2) cout << v << " ";
    cout << "\nvec3: ";
    for (int v : vec3) cout << v << " ";
    cout << "\nvec4 (copy of vec2): ";
    for (int v : vec4) cout << v << " ";
    cout << endl;

    return 0;
}