#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:

    bool canWePlace(vector<int>& position, int dist, int balls) {

        int cntBalls = 1;
        int last = position[0];

        for (int i = 1; i < position.size(); i++) {

            if (position[i] - last >= dist) {

                cntBalls++;
                last = position[i];
            }

            if (cntBalls >= balls)
                return true;
        }

        return false;
    }


    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int n = position.size();

        int low = 1;
        int high = position[n - 1] - position[0];


        while (low <= high) {

            int mid = low + (high - low) / 2;


            if (canWePlace(position, mid, m)) {

                // Distance is possible
                // Try to maximize it
                low = mid + 1;
            }

            else {

                // Distance too large
                high = mid - 1;
            }
        }


        return high;
    }
};


int main() {

    Solution obj;

    vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;

    int ans = obj.maxDistance(position, m);

    cout << "Maximum Minimum Distance = " << ans << endl;

    return 0;
}