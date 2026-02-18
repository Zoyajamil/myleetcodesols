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
    
    // Helper function for preorder traversal
    void preorder(TreeNode* root, vector<int> &arr) {
        
        // Base case
        if (root == nullptr)
            return;
        
        // Root
        arr.push_back(root->val);
        
        // Left subtree
        preorder(root->left, arr);
        
        // Right subtree
        preorder(root->right, arr);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preorder(root, arr);
        return arr;
    }
};

