#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;

        ansRow.push_back(1);

        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }

        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int numRows = 5;

    vector<vector<int>> result = obj.generate(numRows);

    cout << "Pascal's Triangle:\n";

    for (auto row : result) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}