#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {

        int deep = 0;
        int count = 0;

        for (char ch : s) {

            if (ch == '(') {
                deep++;
            }
            else if (ch == ')') {
                deep--;
            }

            count = max(count, deep);
        }

        return count;
    }
};

int main() {

    Solution obj;

    string s = "(1+(2*3)+((8)/4))+1";

    cout << "Maximum Nesting Depth: "
         << obj.maxDepth(s) << endl;

    return 0;
}