#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Input array
    vector<int> nums = {3, 0, 1};

    int result = obj.missingNumber(nums);

    cout << "Missing Number = " << result << endl;

    return 0;
}