#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {

        string result = "";
        int level = 0;

        for (char ch : s) {

            if (ch == '(') {

                // Ignore the outermost '('
                if (level > 0) {
                    result += ch;
                }

                level++;
            }

            else {

                level--;

                // Ignore the outermost ')'
                if (level > 0) {
                    result += ch;
                }
            }
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s = "(()())(())";

    string ans = obj.removeOuterParentheses(s);

    cout << "Result = " << ans << endl;

    return 0;
}