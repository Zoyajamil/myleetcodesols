/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using namespace std;

class Solution {
public:
    
    void dfs(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;
        
        // If visiting this level for the first time
        if (res.size() == level)
            res.push_back(node->val);
        
        // Visit right first
        dfs(node->right, level + 1, res);
        dfs(node->left, level + 1, res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};
