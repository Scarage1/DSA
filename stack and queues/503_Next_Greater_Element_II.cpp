#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> nge(n, -1);

        stack<int> st;

        // Traverse the array twice
        for (int i = 2 * n - 1; i >= 0; i--) {

            int current = nums[i % n];

            // Remove elements that cannot be the
            // next greater element
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            // Store answer only during the first pass
            if (i < n) {
                if (!st.empty())
                    nge[i] = st.top();
            }

            // Add current element to stack
            st.push(current);
        }

        return nge;
    }
};

void printVector(const vector<int>& nums) {

    cout << "[";

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];

        if (i + 1 < nums.size())
            cout << ", ";
    }

    cout << "]" << endl;
}

int main() {

    Solution obj;

    vector<int> nums = {1, 2, 1};

    cout << "Input: ";
    printVector(nums);

    vector<int> answer = obj.nextGreaterElements(nums);

    cout << "Output: ";
    printVector(answer);

    return 0;
}