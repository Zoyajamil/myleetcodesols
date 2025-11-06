// LeetCode: Binary Tree Maximum Path Sum
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
    int maxSum = INT_MIN;

    int gain(TreeNode* node) {
        if (!node) return 0;
        int left = max(0, gain(node->left));
        int right = max(0, gain(node->right));
        maxSum = max(maxSum, left + right + node->val);
        return node->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        gain(root);
        return maxSum;
    }
};

