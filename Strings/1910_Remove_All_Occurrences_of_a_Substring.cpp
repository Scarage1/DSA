#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {

        while (s.length() > 0 && s.find(part) < s.length()) {

            s.erase(s.find(part), part.length());
        }

        return s;
    }
};

int main() {

    Solution obj;

    string s = "daabcbaabcbc";
    string part = "abc";

    string ans = obj.removeOccurrences(s, part);

    cout << "Result = " << ans << endl;

    return 0;
}