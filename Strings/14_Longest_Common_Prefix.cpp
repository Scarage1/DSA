#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) {
            return "";
        }

        string first = strs[0];

        // Traverse each character of the first string
        for (int i = 0; i < first.length(); i++) {

            // Compare with all remaining strings
            for (int j = 1; j < strs.size(); j++) {

                // String ended OR character mismatch
                if (i >= strs[j].length() || first[i] != strs[j][i]) {

                    return first.substr(0, i);
                }
            }
        }

        return first;
    }
};

int main() {

    Solution obj;

    vector<string> strs = {"flower", "flow", "flight"};

    string ans = obj.longestCommonPrefix(strs);

    cout << "Longest Common Prefix = " << ans << endl;

    return 0;
}