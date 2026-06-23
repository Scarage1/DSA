#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {

                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicates
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = obj.threeSum(nums);

    cout << "Triplets whose sum is 0:\n";

    for (auto v : ans) {
        cout << "[ ";
        for (int x : v)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}