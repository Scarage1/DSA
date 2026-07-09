#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:

    int sumByD(vector<int>& nums, int div) {

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            // ceil(nums[i] / div)
            sum += (nums[i] + div - 1) / div;
        }

        return sum;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;

        int high = *max_element(nums.begin(), nums.end());


        while (low <= high) {

            int mid = low + (high - low) / 2;


            int sum = sumByD(nums, mid);


            // possible divisor
            if (sum <= threshold) {

                // try smaller divisor
                high = mid - 1;
            }


            // divisor too small
            else {

                low = mid + 1;
            }
        }


        return low;
    }
};


int main() {

    Solution obj;


    vector<int> nums = {1, 2, 5, 9};

    int threshold = 6;


    int ans = obj.smallestDivisor(nums, threshold);


    cout << "Smallest Divisor = " << ans << endl;


    return 0;
}