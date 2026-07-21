#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {

        string vowels = "";

        // Collect all vowels
        for (char ch : s) {
            if (ch == 'a' || ch == 'A' ||
                ch == 'e' || ch == 'E' ||
                ch == 'i' || ch == 'I' ||
                ch == 'o' || ch == 'O' ||
                ch == 'u' || ch == 'U') {

                vowels.push_back(ch);
            }
        }

        // Reverse collected vowels
        reverse(vowels.begin(), vowels.end());

        int j = 0;

        // Replace vowels with reversed vowels
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == 'a' || s[i] == 'A' ||
                s[i] == 'e' || s[i] == 'E' ||
                s[i] == 'i' || s[i] == 'I' ||
                s[i] == 'o' || s[i] == 'O' ||
                s[i] == 'u' || s[i] == 'U') {

                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};

int main() {

    Solution obj;

    string s = "hello";

    cout << "Original String : " << s << endl;
    cout << "After Reversing Vowels : "
         << obj.reverseVowels(s) << endl;

    return 0;
}