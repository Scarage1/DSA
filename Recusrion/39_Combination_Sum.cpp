#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void findCombination(
        int ind,
        int target,
        vector<int>& arr,
        vector<vector<int>>& ans,
        vector<int>& ds
    ) {

        // Base case
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // Pick the current element
        if (arr[ind] <= target) {

            ds.push_back(arr[ind]);

            // Same index because
            // an element can be used multiple times
            findCombination(
                ind,
                target - arr[ind],
                arr,
                ans,
                ds
            );

            // Backtrack
            ds.pop_back();
        }

        // Don't pick the current element
        findCombination(
            ind + 1,
            target,
            arr,
            ans,
            ds
        );
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target
    ) {

        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(
            0,
            target,
            candidates,
            ans,
            ds
        );

        return ans;
    }
};

void printResult(vector<vector<int>>& result) {

    cout << "[";

    for (int i = 0; i < result.size(); i++) {

        cout << "[";

        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j + 1 < result[i].size())
                cout << ",";
        }

        cout << "]";

        if (i + 1 < result.size())
            cout << ",";
    }

    cout << "]\n";
}

int main() {

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution obj;

    vector<vector<int>> result =
        obj.combinationSum(candidates, target);

    cout << "Candidates: ";

    for (int x : candidates)
        cout << x << " ";

    cout << "\nTarget: " << target << endl;

    cout << "Combinations: ";
    printResult(result);

    return 0;
}