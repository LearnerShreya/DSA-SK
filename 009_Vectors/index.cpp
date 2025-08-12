#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> vec (5, 0);                    // Vector of size 5 with values (0)

    for (int i : vec) {               // for each loop
        cout << i << " ";
    }
    cout << endl;


    vector<char> vect = {'a', 'b', 'c', 'd', 'e'};

    for (char val : vect) {               // for each loop
        cout << val << " ";
    }

    return 0;
}