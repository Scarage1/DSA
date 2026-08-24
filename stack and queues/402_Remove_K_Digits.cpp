#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

        // Use string as a stack
        string st;

        for (char ch : num) {

            // Remove larger previous digits
            // to make the number smaller
            while (!st.empty() && k > 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }

            st.push_back(ch);
        }

        // If removals are still remaining,
        // remove digits from the end
        while (k > 0) {
            st.pop_back();
            k--;
        }

        // Remove leading zeroes
        int pos = 0;

        while (pos < st.size() && st[pos] == '0') {
            pos++;
        }

        // Everything was zero
        if (pos == st.size()) {
            return "0";
        }

        return st.substr(pos);
    }
};

int main() {

    Solution obj;

    string num;
    int k;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter k: ";
    cin >> k;

    cout << "Smallest number = "
         << obj.removeKdigits(num, k)
         << endl;

    return 0;
}