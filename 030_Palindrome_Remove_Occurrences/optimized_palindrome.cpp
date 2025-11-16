#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlphaNum(char ch) {
        // Check if character is alphanumeric (letter or digit)

        // if ((ch >= 'a' && ch <= 'z') ||
        //     (ch >= 'A' && ch <= 'Z') ||
        //     (ch >= '0' && ch <= '9'))
        if ((ch >= '0' && ch <= '9') || 
        (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
            return true;
        return false;
    }

    bool isPalindrome(string s) {
        int st = 0;
        int end = s.length() - 1;

        while (st < end) {
            // Skip non-alphanumeric characters from start
            if (!isAlphaNum(s[st])) {
                st++;
                continue;
            }

            // Skip non-alphanumeric characters from end
            if (!isAlphaNum(s[end])) {
                end--;
                continue;
            }

            // Compare lowercase versions of characters
            if (tolower(s[st]) != tolower(s[end]))
                return false;

            // Move both pointers
            st++;
            end--;
        }
        return true;
    }
};

int main() {
    Solution obj;
    string s = "A man, a plan, a canal: Panama";
    cout << (obj.isPalindrome(s) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}