#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0;
        int ten = 0;

        for (int bill : bills) {

            if (bill == 5) {
                five++;
            }

            else if (bill == 10) {

                // Need one $5 bill as change
                if (five > 0) {
                    five--;
                    ten++;
                }
                else {
                    return false;
                }
            }

            else { // bill == 20

                // Prefer $10 + $5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }

                // Otherwise use three $5 bills
                else if (five >= 3) {
                    five -= 3;
                }

                else {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    vector<int> bills = {5, 5, 5, 10, 20};

    cout << "Bills: ";

    for (int bill : bills) {
        cout << bill << " ";
    }

    cout << "\nCan provide change: "
         << (obj.lemonadeChange(bills) ? "true" : "false")
         << endl;

    return 0;
}