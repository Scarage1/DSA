#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {

            // If there is no overlap, add the interval
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            // Otherwise merge the intervals
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    vector<vector<int>> ans = obj.merge(intervals);

    cout << "Merged Intervals:\n";

    for (auto interval : ans) {
        cout << "[ ";
        for (int x : interval) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}