#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int cnt = 0;
        int noOfB = 0;


        for (int i = 0; i < bloomDay.size(); i++) {

            // flower bloomed
            if (bloomDay[i] <= day) {

                cnt++;
            }

            // streak breaks
            else {

                noOfB += (cnt / k);
                cnt = 0;
            }
        }


        // remaining consecutive flowers
        noOfB += (cnt / k);


        return noOfB >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        long long val = 1LL * m * k;


        // impossible case
        if (val > bloomDay.size())
            return -1;


        int mini = INT_MAX;
        int maxi = INT_MIN;


        // find search range
        for (int i = 0; i < bloomDay.size(); i++) {

            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }


        int low = mini;
        int high = maxi;


        while (low <= high) {

            int mid = low + (high - low) / 2;


            if (possible(bloomDay, mid, m, k)) {

                // possible answer
                // try smaller days

                high = mid - 1;
            }

            else {

                // need more days

                low = mid + 1;
            }
        }


        return low;
    }
};


int main() {

    Solution obj;


    vector<int> bloomDay = {1, 10, 3, 10, 2};

    int m = 3;
    int k = 1;


    int ans = obj.minDays(bloomDay, m, k);


    cout << "Minimum Days = " << ans << endl;


    return 0;
}