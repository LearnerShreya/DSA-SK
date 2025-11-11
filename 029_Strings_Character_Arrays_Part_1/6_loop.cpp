#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "apna college.";

    for (char ch : str) {   // range-based for loop
        cout << ch << " ";
    }

    cout << endl;
    return 0;
}