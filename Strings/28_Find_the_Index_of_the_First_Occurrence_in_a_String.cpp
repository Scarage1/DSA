#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        size_t pos = haystack.find(needle);

        if (pos == string::npos) {
            return -1;
        }

        return pos;
    }
};

int main() {

    Solution obj;

    string haystack = "sadbutsad";
    string needle = "sad";

    int index = obj.strStr(haystack, needle);

    if (index == -1) {
        cout << "Substring not found." << endl;
    }
    else {
        cout << "Substring found at index: " << index << endl;
    }

    return 0;
}