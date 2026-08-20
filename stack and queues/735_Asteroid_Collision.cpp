#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> st;

        for (int asteroid : asteroids) {

            // Positive asteroid moves right
            if (asteroid > 0) {
                st.push_back(asteroid);
            }
            else {

                // Current asteroid moves left
                while (!st.empty() &&
                       st.back() > 0 &&
                       st.back() < abs(asteroid)) {

                    st.pop_back();
                }

                // Both asteroids have the same size
                // so both explode
                if (!st.empty() &&
                    st.back() == abs(asteroid)) {

                    st.pop_back();
                }

                // Current negative asteroid survives
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroid);
                }
            }
        }

        return st;
    }
};

void printVector(const vector<int>& nums) {

    cout << "[";

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];

        if (i + 1 < nums.size()) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

int main() {

    Solution obj;

    vector<int> asteroids = {5, 10, -5};

    cout << "Input: ";
    printVector(asteroids);

    vector<int> result = obj.asteroidCollision(asteroids);

    cout << "Output: ";
    printVector(result);

    return 0;
}