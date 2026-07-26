#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int maxi = INT_MIN;
        int secondMaxi = INT_MIN;
        int thirdMaxi = INT_MIN;

        int mini = INT_MAX;
        int secondMini = INT_MAX;

        for (int num : nums) {

            // Update three largest numbers
            if (num > maxi) {
                thirdMaxi = secondMaxi;
                secondMaxi = maxi;
                maxi = num;
            }
            else if (num > secondMaxi) {
                thirdMaxi = secondMaxi;
                secondMaxi = num;
            }
            else if (num > thirdMaxi) {
                thirdMaxi = num;
            }

            // Update two smallest numbers
            if (num < mini) {
                secondMini = mini;
                mini = num;
            }
            else if (num < secondMini) {
                secondMini = num;
            }
        }

        int product1 = maxi * secondMaxi * thirdMaxi;
        int product2 = maxi * mini * secondMini;

        return max(product1, product2);
    }
};

int main() {

    Solution obj;

    vector<int> nums = {-10, -10, 5, 2};

    cout << "Array: ";

    for (int num : nums)
        cout << num << " ";

    cout << endl;

    cout << "Maximum Product = " << obj.maximumProduct(nums) << endl;

    return 0;
}