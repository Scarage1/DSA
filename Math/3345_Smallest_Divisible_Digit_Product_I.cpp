#include <iostream>
using namespace std;

class Solution {
public:
    // Returns the product of digits of num
    int digitProduct(int num) {

        int product = 1;

        while (num > 0) {
            product *= (num % 10);
            num /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {

        while (true) {

            if (digitProduct(n) % t == 0)
                return n;

            n++;
        }
    }
};

int main() {

    Solution obj;

    int n, t;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter t: ";
    cin >> t;

    int ans = obj.smallestNumber(n, t);

    cout << "\nSmallest Number = " << ans << endl;

    return 0;
}