#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        // Edge cases
        if (n == 1)
            return nums[0];

        if (nums[0] != nums[1])
            return nums[0];

        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];


        int low = 1;
        int high = n - 2;


        while (low <= high) {

            int mid = low + (high - low) / 2;


            // Found single element
            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {

                return nums[mid];
            }


            // We are on the correct half
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {

                // Single element is on right
                low = mid + 1;
            }


            else {

                // Single element is on left
                high = mid - 1;
            }
        }


        return -1;
    }
};


int main() {

    Solution obj;


    vector<int> nums = {1,1,2,3,3,4,4,8,8};


    int ans = obj.singleNonDuplicate(nums);


    cout << "Single Element = " << ans << endl;


    return 0;
}