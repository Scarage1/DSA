#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initialize with the first possible triplet
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                // Update closest sum
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum < target) {
                    j++;
                }
                else if (sum > target) {
                    k--;
                }
                else {
                    // Exact match found
                    return sum;
                }
            }
        }

        return closest;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int ans = obj.threeSumClosest(nums, target);

    cout << "Closest Sum = " << ans << endl;

    return 0;
}