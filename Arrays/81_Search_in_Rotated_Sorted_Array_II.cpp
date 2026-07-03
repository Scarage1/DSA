#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target) {
                return true;
            }


            // Duplicate case
            // Cannot decide sorted half
            if (nums[low] == nums[mid] &&
                nums[mid] == nums[high]) {

                low++;
                high--;
                continue;
            }


            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                if (target >= nums[low] &&
                    target <= nums[mid]) {

                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }


            // Right half is sorted
            else {

                if (target >= nums[mid] &&
                    target <= nums[high]) {

                    low = mid + 1;
                }
                else {

                    high = mid - 1;
                }
            }
        }

        return false;
    }
};


int main() {

    Solution obj;

    vector<int> nums = {2,5,6,0,0,1,2};

    int target = 0;

    bool ans = obj.search(nums, target);

    if (ans)
        cout << "Target Found" << endl;
    else
        cout << "Target Not Found" << endl;


    return 0;
}