#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int value) {

        long long val = value;

        if (st.empty()) {
            mini = val;
            st.push(val);
        }
        else if (val >= mini) {
            st.push(val);
        }
        else {
            // Encode the new minimum
            st.push(2 * val - mini);
            mini = val;
        }
    }

    void pop() {

        long long x = st.top();
        st.pop();

        // x is encoded if x < mini
        if (x < mini) {
            mini = 2 * mini - x;
        }
    }

    int top() {

        long long x = st.top();

        // Encoded value represents current minimum
        if (x < mini) {
            return (int)mini;
        }

        return (int)x;
    }

    int getMin() {

        return (int)mini;
    }
};

int main() {

    MinStack st;

    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    return 0;
}