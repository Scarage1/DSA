#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            // Push opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Check ')'
            else if (ch == ')') {

                if (st.empty() || st.top() != '(') {
                    return false;
                }

                st.pop();
            }

            // Check '}'
            else if (ch == '}') {

                if (st.empty() || st.top() != '{') {
                    return false;
                }

                st.pop();
            }

            // Check ']'
            else if (ch == ']') {

                if (st.empty() || st.top() != '[') {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {

    Solution obj;

    string s = "()[]{}";

    if (obj.isValid(s)) {
        cout << "Valid Parentheses" << endl;
    }
    else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}