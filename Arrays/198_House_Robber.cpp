#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++) {

            int pick = nums[i];
            if (i > 1)
                pick += prev2;

            int notPick = prev;

            int cur = max(pick, notPick);

            prev2 = prev;
            prev = cur;
        }

        return prev;
    }
};

int main() {

    Solution obj;

    // Input array
    vector<int> nums = {2, 7, 9, 3, 1};

    int ans = obj.rob(nums);

    cout << "Maximum Money Robbed = " << ans << endl;

    return 0;
}