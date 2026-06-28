#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        // First element must be 1
        arr[0] = 1;

        // Adjust the remaining elements
        for (int i = 1; i < arr.size(); i++) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        // Maximum element after rearranging
        return arr.back();
    }
};

int main() {

    Solution obj;

    vector<int> arr = {2, 2, 1, 2, 1};

    int ans = obj.maximumElementAfterDecrementingAndRearranging(arr);

    cout << "Maximum Element = " << ans << endl;

    cout << "Modified Array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}