#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);

        return ch == 'a' || ch == 'e' ||
               ch == 'i' || ch == 'o' ||
               ch == 'u';
    }

    string reverseVowels(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Move left pointer to next vowel
            while (left < right && !isVowel(s[left])) {
                left++;
            }

            // Move right pointer to previous vowel
            while (left < right && !isVowel(s[right])) {
                right--;
            }

            // Swap vowels
            swap(s[left], s[right]);

            left++;
            right--;
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