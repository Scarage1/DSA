#include <bits/stdc++.h>
#include <iostream> 
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {

        char ans = 0;

        // XOR all characters of s
        for (char ch : s) {
            ans ^= ch;
        }

        // XOR all characters of t
        for (char ch : t) {
            ans ^= ch;
        }

        return ans;
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