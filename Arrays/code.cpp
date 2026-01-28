#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    // Initialize a vector with some integers
    vector<int> numbers = {5, 2, 9, 1, 5, 6};

    // Sort the vector in ascending order
    sort(numbers.begin(), numbers.end());

    
    cout << "Sorted numbers: ";
    for (const int& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Size of the vector: " << numbers.size() << endl;
    cout << "First element: " << numbers.front() << endl;
    cout << "Last element: " << numbers.back() << endl;
    cout <<"end"<<endl;
    return 0;
}