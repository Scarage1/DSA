#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;

        // Store all elements in the set
        for (int x : nums) {
            st.insert(x);
        }

        // Start with the first positive multiple of k
        int multiple = k;

        // Keep checking multiples of k
        while (st.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {8, 2, 3, 4, 6};
    int k = 2;

    cout << "nums: ";

    for (int x : nums) {
        cout << x << " ";
    }

    cout << "\nk = " << k << endl;

    cout << "Smallest Missing Multiple = "
         << obj.missingMultiple(nums, k)
         << endl;

    return 0;
}