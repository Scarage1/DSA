#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> freq;

        // Store frequency of elements in nums1
        for (int x : nums1) {
            freq[x]++;
        }

        vector<int> ans;

        // Check elements of nums2
        for (int x : nums2) {
            if (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> ans = obj.intersect(nums1, nums2);

    cout << "Intersection: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}