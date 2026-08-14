#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mp;

        // Find NGE for every element in nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {

            // Remove elements that cannot be the
            // next greater element
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    cout << "Answer: [";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if (i + 1 < ans.size())
            cout << ", ";
    }

    cout << "]" << endl;

    return 0;
}