#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {

        // Traverse from the end
        for (int i = num.length() - 1; i >= 0; i--) {

            // Check if the digit is odd
            if ((num[i] - '0') % 2 == 1) {

                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};

int main() {

    Solution obj;

    string num = "35427";

    string ans = obj.largestOddNumber(num);

    cout << "Largest Odd Number = " << ans << endl;

    return 0;
}