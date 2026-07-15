#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:

    bool isFreqSame(int freq1[], int freq2[]) {

        for (int i = 0; i < 26; i++) {

            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }


    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) {
            return false;
        }

        int freq1[26] = {0};
        int freq2[26] = {0};


        // Frequency of s1
        for (char ch : s1) {
            freq1[ch - 'a']++;
        }


        int windowSize = s1.length();


        // Build first window
        for (int i = 0; i < windowSize; i++) {
            freq2[s2[i] - 'a']++;
        }


        if (isFreqSame(freq1, freq2)) {
            return true;
        }


        // Slide the window
        for (int i = windowSize; i < s2.length(); i++) {

            // Add new character
            freq2[s2[i] - 'a']++;

            // Remove old character
            freq2[s2[i - windowSize] - 'a']--;

            if (isFreqSame(freq1, freq2)) {
                return true;
            }
        }

        return false;
    }
};


int main() {

    Solution obj;

    string s1 = "ab";
    string s2 = "eidbaooo";

    bool ans = obj.checkInclusion(s1, s2);

    if (ans) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}