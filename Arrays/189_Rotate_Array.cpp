#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int> temp(k);

        // Store last k elements
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Shift remaining elements to the right
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Copy stored elements to the beginning
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    obj.rotate(nums, k);

    cout << "Rotated array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}