#include <iostream>
using namespace std;

class Solution {
public:

    // Recursive Binary Exponentiation
    double power(double x, long long n) {

        // Base case
        if (n == 0)
            return 1.0;

        // Compute x^(n/2)
        double half = power(x, n / 2);

        // If exponent is even
        if (n % 2 == 0)
            return half * half;

        // If exponent is odd
        return x * half * half;
    }

    double myPow(double x, int n) {

        long long nn = n;

        // Handle negative exponent
        if (nn < 0)
            return 1.0 / power(x, -nn);

        return power(x, nn);
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