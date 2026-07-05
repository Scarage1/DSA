#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        // Only one element
        if (n == 1)
            return 0;

        // First element is peak
        if (nums[0] > nums[1])
            return 0;

        // Last element is peak
        if (nums[n - 1] > nums[n - 2])
            return n - 1;


        int low = 1;
        int high = n - 2;


        while (low <= high) {

            int mid = low + (high - low) / 2;


            // Peak condition
            if (nums[mid] > nums[mid - 1] &&
                nums[mid] > nums[mid + 1]) {

                return mid;
            }


            // We are on increasing slope
            // Peak exists on right side
            else if (nums[mid] > nums[mid - 1]) {

                low = mid + 1;
            }


            // We are on decreasing slope
            // Peak exists on left side
            else {

                high = mid - 1;
            }
        }


        return -1;
    }
};


int main() {

    Solution obj;


    vector<int> nums = {1, 2, 3, 1};


    int index = obj.findPeakElement(nums);


    cout << "Peak Element Index = " << index << endl;
    cout << "Peak Element Value = " << nums[index] << endl;


    return 0;
}