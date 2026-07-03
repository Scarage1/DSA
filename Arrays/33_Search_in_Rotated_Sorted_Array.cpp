#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Check if left half is sorted
            if (nums[low] <= nums[mid]) {

                // Target lies in left half
                if (target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // Otherwise right half is sorted
            else {

                // Target lies in right half
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};

    int target = 0;

    int index = obj.search(nums, target);

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}