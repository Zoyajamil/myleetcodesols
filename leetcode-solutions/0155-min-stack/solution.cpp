// LeetCode: Min Stack
#include <stack>
#include <limits>
using namespace std;

class MinStack {
    stack<int> st, mn;
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (mn.empty() || val <= mn.top()) mn.push(val);
    }

    void pop() {
        if (st.top() == mn.top()) mn.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mn.top();
    }
};

