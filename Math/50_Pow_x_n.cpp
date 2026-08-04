#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1.0;

        // Use long long to handle INT_MIN
        long long nn = n;

        // Convert negative exponent to positive
        if (nn < 0)
            nn = -nn;

        while (nn > 0) {

            // If exponent is odd
            if (nn % 2 == 1) {
                ans *= x;
                nn--;
            }
            // If exponent is even
            else {
                x *= x;
                nn /= 2;
            }
        }

        // Handle negative exponent
        if (n < 0)
            ans = 1.0 / ans;

        return ans;
    }
};

int main() {

    Solution obj;

    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    cout << "\nResult = " << obj.myPow(x, n) << endl;

    return 0;
}