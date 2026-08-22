#include <iostream>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {

        int sum = 0;
        int product = 1;

        int temp = n;

        while (temp > 0) {

            int digit = temp % 10;

            sum += digit;
            product *= digit;

            temp /= 10;
        }

        return n % (sum + product) == 0;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter number: ";
    cin >> n;

    if (obj.checkDivisibility(n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}