#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        if (nums.size() < 2) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int maxDiff = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            int diff = nums[i + 1] - nums[i];
            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {3, 6, 9, 1};

    int ans = obj.maximumGap(nums);

    cout << "Maximum Gap = " << ans << endl;

    return 0;
}