#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int low = 0;
        int high = arr.size() - 1;


        while (low <= high) {

            int mid = low + (high - low) / 2;


            // numbers missing before arr[mid]
            int missing = arr[mid] - (mid + 1);


            if (missing < k) {

                // kth missing is on right side
                low = mid + 1;
            }

            else {

                // kth missing is on left side
                high = mid - 1;
            }
        }


        return k + high + 1;
    }
};


int main() {

    Solution obj;


    vector<int> arr = {2,3,4,7,11};

    int k = 5;


    int ans = obj.findKthPositive(arr, k);


    cout << "Kth Missing Positive Number = " << ans << endl;


    return 0;
}