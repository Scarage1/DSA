#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        int n = s.length();
        string ans = "";

        // Reverse the entire string
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {

            string word = "";

            // Extract one word
            while (i < n && s[i] != ' ') {

                word += s[i];
                i++;
            }

            // Reverse the extracted word
            reverse(word.begin(), word.end());

            // Ignore extra spaces
            if (word.length() > 0) {

                ans += " " + word;
            }
        }

        // Remove leading space
        return ans.substr(1);
    }
};

int main() {

    Solution obj;

    string s = "the sky is blue";

    string ans = obj.reverseWords(s);

    cout << "Reversed Words = " << ans << endl;

    return 0;
}