#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isAlphaNum(char ch) {

        if ((tolower(ch) >= 'a' && tolower(ch) <= 'z') ||
            (ch >= '0' && ch <= '9')) {
            return true;
        }

        return false;
    }

    bool isPalindrome(string s) {

        int start = 0;
        int end = s.length() - 1;

        while (start < end) {

            if (!isAlphaNum(s[start])) {
                start++;
                continue;
            }

            if (!isAlphaNum(s[end])) {
                end--;
                continue;
            }

            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s = "A man, a plan, a canal: Panama";

    if (obj.isPalindrome(s))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}