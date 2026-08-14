#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {

        int freq[26] = {0};

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            // Add current character
            freq[s[right] - 'a']++;

            // If current character occurs more than twice,
            // shrink the window from the left.
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            // Current window is valid
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Maximum Length = "
         << obj.maximumLengthSubstring(s)
         << endl;

    return 0;
}