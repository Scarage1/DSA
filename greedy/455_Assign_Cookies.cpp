#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int n = g.size();
        int m = s.size();

        int child = 0;
        int cookie = 0;

        // Sort greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (child < n && cookie < m) {

            // Current cookie can satisfy current child
            if (g[child] <= s[cookie]) {
                child++;
            }

            // Current cookie is used/discarded
            cookie++;
        }

        return child;
    }
};

int main() {

    Solution obj;

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    cout << "Greed factors: ";

    for (int x : g) {
        cout << x << " ";
    }

    cout << "\nCookies: ";

    for (int x : s) {
        cout << x << " ";
    }

    cout << "\nContent Children: "
         << obj.findContentChildren(g, s)
         << endl;

    return 0;
}