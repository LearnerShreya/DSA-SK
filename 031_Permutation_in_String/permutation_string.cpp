#include <iostream>
using namespace std;

class Solution {
public:
    bool isFreqSame(int f1[], int f2[]) {
        for(int i = 0; i < 26; i++)
            if(f1[i] != f2[i]) return false;
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        int freq1[26] = {0}, freq2[26] = {0};
        int k = s1.length();

        for(char c : s1) freq1[c - 'a']++;
        for(int i = 0; i < k; i++) freq2[s2[i] - 'a']++;

        if(isFreqSame(freq1, freq2)) return true;

        for(int i = k; i < s2.length(); i++) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - k] - 'a']--;
            if(isFreqSame(freq1, freq2)) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    cout << (sol.checkInclusion("ab", "eidbaooo") ? "true" : "false")<<endl;
    return 0;
}