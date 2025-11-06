/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// LeetCode: Populating Next Right Pointers in Each Node II
#include <queue>
using namespace std;

// Definition for a Node is provided by LeetCode:
// class Node { public: int val; Node* left; Node* right; Node* next; };

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* level = root;
        while (level) {
            Node dummy(0);
            Node* tail = &dummy;
            for (Node* curr = level; curr; curr = curr->next) {
                if (curr->left) { tail->next = curr->left; tail = tail->next; }
                if (curr->right){ tail->next = curr->right; tail = tail->next; }
            }
            level = dummy.next;
        }
        return root;
    }
};

