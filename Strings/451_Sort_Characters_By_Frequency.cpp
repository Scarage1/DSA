#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    static bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {

        unordered_map<char, int> mp;

        // Count frequency of each character
        for (char ch : s) {
            mp[ch]++;
        }

        // Store map entries into a vector
        vector<pair<char, int>> v;

        for (auto it : mp) {
            v.push_back(it);
        }

        // Sort by frequency in descending order
        sort(v.begin(), v.end(), cmp);

        // Build the answer
        string ans = "";

        for (auto it : v) {
            ans += string(it.second, it.first);
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