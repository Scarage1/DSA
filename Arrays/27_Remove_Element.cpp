#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        // Move all elements not equal to val to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    Solution obj;

    // Input array
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int k = obj.removeElement(nums, val);

    cout << "Number of remaining elements = " << k << endl;

    cout << "Array after removing " << val << ": ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}