#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        // Split the string into words
        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        // Number of pattern characters must equal number of words
        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < pattern.length(); i++) {

            char c1 = pattern[i];
            string c2 = words[i];

            // Check character -> word mapping
            if (mp1.find(c1) != mp1.end()) {
                if (mp1[c1] != c2) {
                    return false;
                }
            }

            // Check word -> character mapping
            if (mp2.find(c2) != mp2.end()) {
                if (mp2[c2] != c1) {
                    return false;
                }
            }

            // Store mappings
            mp1[c1] = c2;
            mp2[c2] = c1;
        }

        return true;
    }
};

int main() {

    Solution obj;

    string pattern = "abba";
    string s = "dog cat cat dog";

    if (obj.wordPattern(pattern, s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}