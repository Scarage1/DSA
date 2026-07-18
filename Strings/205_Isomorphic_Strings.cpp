#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {

            char c1 = s[i];
            char c2 = t[i];

            // Check mapping from s -> t
            if (mp1.find(c1) != mp1.end()) {
                if (mp1[c1] != c2) {
                    return false;
                }
            }

            // Check mapping from t -> s
            if (mp2.find(c2) != mp2.end()) {
                if (mp2[c2] != c1) {
                    return false;
                }
            }

            // Store the mappings
            mp1[c1] = c2;
            mp2[c2] = c1;
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s = "paper";
    string t = "title";

    if (obj.isIsomorphic(s, t)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}