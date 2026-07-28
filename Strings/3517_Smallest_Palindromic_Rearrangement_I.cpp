#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left, middle;

        // Build left half and middle character
        for (int i = 0; i < 26; i++) {

            // Add half of the occurrences
            left.append(freq[i] / 2, char(i + 'a'));

            // If frequency is odd, this character goes in the middle
            if (freq[i] % 2 == 1) {
                middle = char(i + 'a');
            }
        }

        // Right half is reverse of left half
        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};

int main() {

    Solution obj;

    vector<string> testCases = {
        "daccad",
        "babab",
        "aabb",
        "racecar",
        "zz"
    };

    for (string s : testCases) {

        cout << "Input : " << s << endl;
        cout << "Output: " << obj.smallestPalindrome(s) << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}