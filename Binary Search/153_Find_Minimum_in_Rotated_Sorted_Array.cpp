#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        int mini = INT_MAX;

        while (low <= high) {

            int mid = low + (high - low) / 2;


            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                // Minimum of sorted half is first element
                mini = min(mini, nums[low]);

                // eliminate left half
                low = mid + 1;
            }


            // Right half is sorted
            else {

                // mid can be the minimum
                mini = min(mini, nums[mid]);

                // eliminate right half
                high = mid - 1;
            }
        }

        return mini;
    }
};


int main() {

    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};

    int ans = obj.findMin(nums);

    cout << "Minimum Element = " << ans << endl;

    return 0;
}