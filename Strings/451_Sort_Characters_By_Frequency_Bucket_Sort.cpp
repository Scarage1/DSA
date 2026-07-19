#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count frequency of each character
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        // Step 2: Create buckets
        // bucket[i] stores all characters having frequency i
        vector<vector<char>> bucket(s.length() + 1);

        for (auto it : mp) {
            char ch = it.first;
            int freq = it.second;

            bucket[freq].push_back(ch);
        }

        // Step 3: Build answer from highest frequency
        string ans = "";

        for (int freq = s.length(); freq >= 1; freq--) {

            for (char ch : bucket[freq]) {

                ans += string(freq, ch);
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "tree";

    cout << obj.frequencySort(s) << endl;

    return 0;
}