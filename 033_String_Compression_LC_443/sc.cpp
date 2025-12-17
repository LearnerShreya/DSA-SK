#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            // count same characters
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // store character
            chars[idx++] = ch;

            // store count if more than 1
            if (count > 1) {
                string str = to_string(count);
                for (char dig : str) {
                    chars[idx++] = dig;
                }
            }

            i--; // adjust index
        }

        return idx;
    }
};

int main() {
    Solution sol;

    vector<char> chars = {'a','a','b','b','c','c','c'};

    int len = sol.compress(chars);

    cout << "Compressed length: " << len << endl;
    cout << "Compressed string: ";

    for (int i = 0; i < len; i++) {
        cout << chars[i];
    }

    return 0;
}