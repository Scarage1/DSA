#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        if (n == 0)
            return 0;

        unordered_set<int> st;

        // Insert all elements into the set
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        int longest = 1;

        // Find the longest consecutive sequence
        for (auto it : st) {

            // Check if it is the start of a sequence
            if (st.find(it - 1) == st.end()) {

                int cnt = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};

int main() {

    Solution obj;

    // Input array
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int ans = obj.longestConsecutive(nums);

    cout << "Longest Consecutive Sequence Length = " << ans << endl;

    return 0;
}