#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Store unique elements of nums1
        unordered_set<int> st(nums1.begin(), nums1.end());

        vector<int> ans;

        // Find common elements
        for (int x : nums2) {
            if (st.find(x) != st.end()) {
                ans.push_back(x);
                st.erase(x);   // Avoid duplicates
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // Input arrays
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> ans = obj.intersection(nums1, nums2);

    cout << "Intersection: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}