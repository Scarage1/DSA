#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {

        vector<int> arr;

        // Store digits
        while (n > 0) {
            arr.push_back(n % 10);
            n /= 10;
        }

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        // Find largest and second largest digits
        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }

        return largest * secondLargest;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Maximum Product = " << obj.maxProduct(n) << endl;

    return 0;
}