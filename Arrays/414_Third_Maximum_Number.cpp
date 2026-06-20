#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;

        for (int x : nums) {

            // Skip duplicates
            if (x == first || x == second || x == third)
                continue;

            if (x > first) {
                third = second;
                second = first;
                first = x;
            }
            else if (x > second) {
                third = second;
                second = x;
            }
            else if (x > third) {
                third = x;
            }
        }

        // If there are less than 3 distinct numbers
        if (third == LONG_MIN)
            return first;

        return third;
    }
};

int main() {

    Solution obj;

    // Input array
    vector<int> nums = {2, 2, 3, 1};

    int ans = obj.thirdMax(nums);

    cout << "Third Maximum Number = " << ans << endl;

    return 0;
}