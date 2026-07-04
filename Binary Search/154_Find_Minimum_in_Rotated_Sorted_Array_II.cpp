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


            // Duplicate case
            // Cannot decide sorted half
            if (nums[low] == nums[mid] &&
                nums[mid] == nums[high]) {

                mini = min(mini, nums[low]);

                low++;
                high--;

                continue;
            }


            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                mini = min(mini, nums[low]);

                // remove left half
                low = mid + 1;
            }


            // Right half is sorted
            else {

                mini = min(mini, nums[mid]);

                // remove right half
                high = mid - 1;
            }
        }

        return mini;
    }
};


int main() {

    Solution obj;

    vector<int> nums = {2,2,2,0,1};

    int ans = obj.findMin(nums);

    cout << "Minimum Element = " << ans << endl;

    return 0;
}