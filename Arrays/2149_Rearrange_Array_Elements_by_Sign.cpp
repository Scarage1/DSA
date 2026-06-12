#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, 0);

        int posIndex = 0;
        int negIndex = 1;

        for (int i = 0; i < n; i++) {

            if (nums[i] < 0) {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // Input array
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> result = obj.rearrangeArray(nums);

    cout << "Rearranged Array: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}