#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {

        int sum = 0;

        for (int i = 0; i < s.length(); i++) {

            int first = i;
            int second = t.find(s[i]);

            sum += abs(first - second);
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