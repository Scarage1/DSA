#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int num : nums) {

            if (num > largest) {
                secondLargest = largest;
                largest = num;
            }
            else if (num >= secondLargest) {
                secondLargest = num;
            }
        }

        return (largest - 1) * (secondLargest - 1);
    }
};

int main() {

    Solution obj;

    vector<int> nums = {3, 4, 5, 2};

    cout << "Array: ";

    for (int num : nums)
        cout << num << " ";

    cout << endl;

    cout << "Maximum Product = " << obj.maxProduct(nums) << endl;

    return 0;
}