#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Frequency array for lowercase English letters
        int freq[26] = {0};

        // Count characters in first string
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Decrease count using second string
        for (char ch : t) {
            freq[ch - 'a']--;
        }

        // If any frequency is not zero,
        // strings are not anagrams
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s = "anagram";
    string t = "nagaram";

    if (obj.isAnagram(s, t))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}