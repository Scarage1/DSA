#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        int start = 0;
        int end = s.size() - 1;

        while (start < end) {

            swap(s[start], s[end]);

            start++;
            end--;
        }
    }
};

int main() {

    Solution obj;

    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    obj.reverseString(s);

    cout << "Reversed String: ";

    for (char ch : s) {
        cout << ch << " ";
    }

    cout << endl;

    return 0;
}