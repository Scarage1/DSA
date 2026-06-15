#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> st;

        for (int x : nums) {

            // If element already exists, duplicate found
            if (st.find(x) != st.end()) {
                return true;
            }

            st.insert(x);
        }

        return false;
    }
};

int main() {

    Solution obj;

    // Input array
    vector<int> nums = {1, 2, 3, 1};

    bool ans = obj.containsDuplicate(nums);

    if (ans)
        cout << "Contains Duplicate" << endl;
    else
        cout << "Does Not Contain Duplicate" << endl;

    return 0;
}