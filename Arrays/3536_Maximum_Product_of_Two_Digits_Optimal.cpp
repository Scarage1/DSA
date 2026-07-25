#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        while (n > 0) {

            int digit = n % 10;

            if (digit > largest) {
                secondLargest = largest;
                largest = digit;
            }
            else if (digit > secondLargest) {
                secondLargest = digit;
            }

            n /= 10;
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