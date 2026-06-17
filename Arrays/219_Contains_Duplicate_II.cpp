#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {

            // If the element is already present
            if (mpp.find(nums[i]) != mpp.end()) {

                // Check the index difference
                if (i - mpp[nums[i]] <= k)
                    return true;
            }

            // Update the latest index of the element
            mpp[nums[i]] = i;
        }

        return false;
    }
};

int main() {

    Solution obj;

    // Input array
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    bool ans = obj.containsNearbyDuplicate(nums, k);

    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}