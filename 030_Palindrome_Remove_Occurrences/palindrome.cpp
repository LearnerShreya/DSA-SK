#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Convert to lowercase
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }

        // Remove non-alphanumeric characters
        string filtered = "";
        for (char ch : s) {
            if (isalnum(ch)) {
                filtered += ch;
            }
        }

        // Two-pointer check
        int st = 0;
        int en = filtered.size() - 1;
        while (st < en) {
            if (filtered[st] != filtered[en]) {
                return false;
            }
            st++;
            en--;
        }

        return true;
    }
};

int main() {
    Solution obj;
    cout << boolalpha; // to print true/false instead of 1/0
    cout << obj.isPalindrome("A man, a plan, a canal: Panama") << endl; // true
    cout << obj.isPalindrome("hello") << endl; // false
    return 0;
}