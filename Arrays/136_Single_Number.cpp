#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;

        for (int i = 0; i < nums.size(); i++) {
            xor1 ^= nums[i];
        }

        return xor1;
    }
};

int main() {
    Solution obj;

    // Input array
    vector<int> nums = {4, 1, 2, 1, 2};

    int ans = obj.singleNumber(nums);

    cout << "Single Number = " << ans << endl;

    return 0;
}