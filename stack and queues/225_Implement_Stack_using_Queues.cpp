#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {

        q.push(x);

        int n = q.size();

        // Move all previous elements
        // behind the newly inserted element
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {

        int x = q.front();
        q.pop();

        return x;
    }

    int top() {

        return q.front();
    }

    bool empty() {

        return q.empty();
    }
};

int main() {

    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;

    cout << "Top: " << st.top() << endl;

    cout << "Is Empty: "
         << (st.empty() ? "true" : "false")
         << endl;

    return 0;
}