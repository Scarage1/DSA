#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {

        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            if (sum == 0) {
                cnt++;
            }
        }

        return cnt;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {2, 3, -5};

    int ans = obj.returnToBoundaryCount(nums);

    cout << "Number of times returned to boundary: " << ans << endl;

    return 0;
}