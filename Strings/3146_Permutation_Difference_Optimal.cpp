#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {

        unordered_map<char, int> pos;

        // Store index of every character in t
        for (int i = 0; i < t.length(); i++) {
            pos[t[i]] = i;
        }

        int sum = 0;

        // Calculate permutation difference
        for (int i = 0; i < s.length(); i++) {
            sum += abs(i - pos[s[i]]);
        }

        return sum;
    }
};

int main() {

    Solution obj;

    string s = "abc";
    string t = "bac";

    cout << "String s : " << s << endl;
    cout << "String t : " << t << endl;

    cout << "Permutation Difference : "
         << obj.findPermutationDifference(s, t) << endl;

    return 0;
}