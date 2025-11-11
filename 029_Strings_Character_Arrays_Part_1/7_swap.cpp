#include <iostream>
#include <vector>
#include <algorithm> // for swap
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0;
        int en = s.size() - 1;

        // while (st < en) {
        //     swap(s[st], s[en]);
        //     st++;
        //     en--;
        // }

        while (st < en)
        swap(s[st++], s[en--]);

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