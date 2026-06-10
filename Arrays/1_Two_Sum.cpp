#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            int moreNeeded = target - nums[i];

            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }

            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }
};

int main() {
    Solution obj;

    // Input array
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = obj.twoSum(nums, target);

    cout << "Indices: " << ans[0] << " " << ans[1] << endl;

    return 0;
}