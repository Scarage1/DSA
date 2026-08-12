#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            // Opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Closing parenthesis
            else if (ch == ')') {

                if (st.empty() || st.top() != '(')
                    return false;

                st.pop();
            }

            // Closing curly bracket
            else if (ch == '}') {

                if (st.empty() || st.top() != '{')
                    return false;

                st.pop();
            }

            // Closing square bracket
            else if (ch == ']') {

                if (st.empty() || st.top() != '[')
                    return false;

                st.pop();
            }
        }

        // Stack must be empty
        // after all brackets are matched
        return st.empty();
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter brackets: ";
    cin >> s;

    if (obj.isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}