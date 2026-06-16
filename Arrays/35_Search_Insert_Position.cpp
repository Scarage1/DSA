#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // Position where target should be inserted
        return low;
    }
};

int main() {

    Solution obj;

    // Input array
    vector<int> nums = {1, 3, 5, 6};

    int target = 5;

    int ans = obj.searchInsert(nums, target);

    cout << "Search Insert Position = " << ans << endl;

    return 0;
}