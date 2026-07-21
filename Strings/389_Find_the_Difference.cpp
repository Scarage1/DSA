#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {

        unordered_map<char, int> mp;

        // Count characters in s
        for (char ch : s) {
            mp[ch]++;
        }

        // Remove characters using t
        for (char ch : t) {
            mp[ch]--;
        }

        // Find the extra character
        for (auto it : mp) {
            if (it.second != 0) {
                return it.first;
            }
        }

        return '\0';
    }
};

int main() {

    Solution obj;

    string s = "abcd";
    string t = "abcde";

    cout << "String s : " << s << endl;
    cout << "String t : " << t << endl;

    cout << "Extra Character : "
         << obj.findTheDifference(s, t) << endl;

    return 0;
}