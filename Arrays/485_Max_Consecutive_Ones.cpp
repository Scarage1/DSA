#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxi = max(maxi, count);
            } else {
                count = 0;
            }
        }

        return maxi;
    }
};

int main() {
    Solution obj;

    // Input array
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    int ans = obj.findMaxConsecutiveOnes(nums);

    cout << "Maximum consecutive ones = " << ans << endl;

    return 0;
}