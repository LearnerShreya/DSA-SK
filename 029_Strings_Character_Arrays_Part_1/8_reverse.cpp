#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end()); // STL function
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution obj;
    obj.reverseString(s);

    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}