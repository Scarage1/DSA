#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    // Next Smaller Element
    vector<int> findNSE(vector<int>& arr) {

        int n = arr.size();

        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    // Previous Smaller Element or Equal
    vector<int> findPSEE(vector<int>& arr) {

        int n = arr.size();

        vector<int> psee(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        int mod = 1e9 + 7;

        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - psee[i];
            long long right = nse[i] - i;

            long long contribution =
                left * right * arr[i];

            total = (total + contribution) % mod;
        }

        return total;
    }
};

void printVector(const vector<int>& arr) {

    cout << "[";

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];

        if (i + 1 < arr.size()) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

int main() {

    Solution obj;

    vector<int> arr = {3, 1, 2, 4};

    cout << "Input: ";
    printVector(arr);

    int answer = obj.sumSubarrayMins(arr);

    cout << "Output: " << answer << endl;

    return 0;
}