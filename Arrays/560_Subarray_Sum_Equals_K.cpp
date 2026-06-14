#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;

        // Base case: prefix sum 0 occurs once
        mpp[0] = 1;

        int preSum = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {

            preSum += nums[i];

            int remove = preSum - k;

            // Add the number of previous prefix sums equal to 'remove'
            cnt += mpp[remove];

            // Store current prefix sum
            mpp[preSum]++;
        }

        return cnt;
    }
};

int main() {

    Solution obj;

    // Input array
    vector<int> nums = {1, 1, 1};
    int k = 2;

    int ans = obj.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k
         << " = " << ans << endl;

    return 0;
}