#include <bits/stdc++.h>
#include<iostream>
using namespace std;


class Solution {
public:
    int targetID(vector<int>& nums, int target, int start, int end) {

        // Base case
        if (start > end)
            return -1;

        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (target < nums[mid]) {
            return targetID(nums, target, start, mid - 1);
        }
        else {
            return targetID(nums, target, mid + 1, end);
        }
    }

    int search(vector<int>& nums, int target) {

        return targetID(nums, target, 0, nums.size() - 1);
    }
};

int main() {

    Solution obj;

    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int index = obj.search(nums, target);

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}