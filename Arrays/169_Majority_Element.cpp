#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el = 0;

        // Moore's Voting Algorithm
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                count = 1;
                el = nums[i];
            }
            else if (nums[i] == el) {
                count++;
            }
            else {
                count--;
            }
        }

        // Verification step
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }

        if (cnt1 > nums.size() / 2) {
            return el;
        }

        return -1;
    }
};

int main() {
    Solution obj;

    // Input array
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int ans = obj.majorityElement(nums);

    cout << "Majority Element = " << ans << endl;

    return 0;
}