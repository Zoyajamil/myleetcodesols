// LeetCode: Implement Stack using Queues
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        // rotate to make the last pushed element at the front
        for (int i = 0; i < (int)q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

