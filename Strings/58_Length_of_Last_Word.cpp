#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.length() - 1;
        int count = 0;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};

int main() {

    Solution obj;

    string s = "Hello World   ";

    cout << "Input String : \"" << s << "\"" << endl;
    cout << "Length of Last Word : "
         << obj.lengthOfLastWord(s) << endl;

    return 0;
}