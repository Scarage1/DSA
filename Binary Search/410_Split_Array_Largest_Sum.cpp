#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:

    // Count the number of subarrays required
    // if the maximum allowed sum of a subarray is 'sum'
    int countSubArray(vector<int>& nums, int sum) {

        int subArray = 1;
        long long sumSubArray = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (sumSubArray + nums[i] <= sum) {

                sumSubArray += nums[i];
            }

            else {

                subArray++;
                sumSubArray = nums[i];
            }
        }

        return subArray;
    }


    int findSum(vector<int>& nums, int n, int m) {

        if (m > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());

        int high = accumulate(nums.begin(), nums.end(), 0);


        while (low <= high) {

            int mid = low + (high - low) / 2;

            int subArray = countSubArray(nums, mid);

            // Possible answer
            if (subArray <= m) {

                high = mid - 1;
            }

            // Need larger maximum sum
            else {

                low = mid + 1;
            }
        }

        return low;
    }


    int splitArray(vector<int>& nums, int k) {

        return findSum(nums, nums.size(), k);
    }
};


int main() {

    Solution obj;

    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    int ans = obj.splitArray(nums, k);

    cout << "Minimum Largest Sum = " << ans << endl;

    return 0;
}