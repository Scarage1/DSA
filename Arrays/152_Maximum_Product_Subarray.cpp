#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int prefix = 1;
        int suffix = 1;

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {

            // Reset if product becomes zero
            if (prefix == 0)
                prefix = 1;

            if (suffix == 0)
                suffix = 1;

            // Left to Right Product
            prefix *= nums[i];

            // Right to Left Product
            suffix *= nums[n - i - 1];

            ans = max(ans, max(prefix, suffix));
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {2, 3, -2, 4};

    int ans = obj.maxProduct(nums);

    cout << "Maximum Product = " << ans << endl;

    return 0;
}