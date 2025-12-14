#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        // Step 1: reverse the whole string
        reverse(s.begin(), s.end());

        int i = 0;
        while(i < n) {
            // skip spaces
            while(i < n && s[i] == ' ') i++;

            string word = "";
            // collect characters of a word
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // reverse each word back to original order
            if(!word.empty()) {
                reverse(word.begin(), word.end());

                if(!ans.empty()) ans += " ";
                ans += word;
            }
        }

        return ans;
    }
};

int main() {
    // Solution obj;

    // string s = "  hello   world  python  ";

    // string result = obj.reverseWords(s);
    // cout << result << endl;

    
    cout<<(Solution().reverseWords("  hello   world  python  "))<<endl;

    return 0;
}