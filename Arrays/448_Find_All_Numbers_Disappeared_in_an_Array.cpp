#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        // Store all numbers in a hash set
        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ans;

        // Check numbers from 1 to n
        for (int i = 1; i <= n; i++) {

            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // Input array
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> ans = obj.findDisappearedNumbers(nums);

    cout << "Missing Numbers: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}