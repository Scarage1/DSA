#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {

        int n = word.length();

        // First 8 characters -> 1 push each
        if (n <= 8) {
            return n;
        }

        // Next 8 characters -> 2 pushes each
        if (n <= 16) {
            return 8 + (n - 8) * 2;
        }

        // Next 8 characters -> 3 pushes each
        if (n <= 24) {
            return 8 + 16 + (n - 16) * 3;
        }

        // Remaining 2 characters -> 4 pushes each
        return 8 + 16 + 24 + (n - 24) * 4;
    }
};

int main() {

    Solution obj;

    vector<string> testCases = {
        "abc",
        "abcdefgh",
        "abcdefghi",
        "abcdefghijklmnop",
        "abcdefghijklmnopq",
        "abcdefghijklmnopqrstuvwxyz"
    };

    for (string word : testCases) {

        cout << "Word   : " << word << endl;
        cout << "Length : " << word.length() << endl;
        cout << "Pushes : " << obj.minimumPushes(word) << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}