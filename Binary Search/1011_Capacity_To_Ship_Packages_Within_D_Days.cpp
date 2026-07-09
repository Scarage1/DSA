#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:

    int dayReq(vector<int>& weights, int cap) {

        int days = 1;
        int load = 0;


        for (int i = 0; i < weights.size(); i++) {

            // Current package cannot fit
            if (load + weights[i] > cap) {

                days++;
                load = weights[i];
            }

            else {

                load += weights[i];
            }
        }


        return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {


        // minimum capacity possible
        int low = *max_element(weights.begin(), weights.end());


        // maximum capacity possible
        int high = accumulate(weights.begin(), weights.end(), 0);



        while (low <= high) {

            int mid = low + (high - low) / 2;


            int requiredDays = dayReq(weights, mid);


            // possible capacity
            if (requiredDays <= days) {

                // try smaller capacity
                high = mid - 1;
            }


            // capacity too small
            else {

                low = mid + 1;
            }
        }


        return low;
    }
};


int main() {

    Solution obj;


    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};

    int days = 5;


    int ans = obj.shipWithinDays(weights, days);


    cout << "Minimum Ship Capacity = " << ans << endl;


    return 0;
}