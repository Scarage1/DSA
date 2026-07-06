#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:

    int findMax(vector<int>& piles) {

        int maxi = INT_MIN;

        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }

        return maxi;
    }


    long long calculateTotalHours(vector<int>& piles, int speed) {

        long long totalH = 0;

        for (int i = 0; i < piles.size(); i++) {

            totalH += ceil((double)piles[i] / (double)speed);
        }

        return totalH;
    }


    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = findMax(piles);


        while (low <= high) {

            int mid = low + (high - low) / 2;


            long long totalH = calculateTotalHours(piles, mid);


            // speed is enough
            if (totalH <= h) {

                high = mid - 1;
            }


            // speed is too slow
            else {

                low = mid + 1;
            }
        }


        return low;
    }
};


int main() {

    Solution obj;


    vector<int> piles = {3, 6, 7, 11};
    int h = 8;


    int ans = obj.minEatingSpeed(piles, h);


    cout << "Minimum Eating Speed = " << ans << endl;


    return 0;
}