#include <bits/stdc++.h>
#include <iostream> 
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {

        string ans = "";

        for (int i = 0; i < num.length() - 2; i++) {

            // Check if three consecutive digits are the same
            if (num[i] == num[i + 1] &&
                num[i + 1] == num[i + 2]) {

                string curr = num.substr(i, 3);

                ans = max(ans, curr);
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string num = "6777133339";

    string ans = obj.largestGoodInteger(num);

    cout << "Largest Good Integer = " << ans << endl;

    return 0;
}