#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int l = 0;
        int r = height.size() - 1;

        int lMax = 0;
        int rMax = 0;

        int total = 0;

        while (l < r) {

            // Process the side with the smaller height
            if (height[l] <= height[r]) {

                if (height[l] < lMax) {
                    total += lMax - height[l];
                }
                else {
                    lMax = height[l];
                }

                l++;
            }
            else {

                if (height[r] < rMax) {
                    total += rMax - height[r];
                }
                else {
                    rMax = height[r];
                }

                r--;
            }
        }

        return total;
    }
};

int main() {

    Solution obj;

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << "Heights: ";

    for (int h : height)
        cout << h << " ";

    cout << endl;

    cout << "Trapped Water = "
         << obj.trap(height)
         << endl;

    return 0;
}