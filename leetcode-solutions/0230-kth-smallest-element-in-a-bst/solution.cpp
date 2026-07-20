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
class Solution {
public:
    vector<int> list; 
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return list[k-1];
    }

    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root->left);
        list.push_back(root->val);
        inorder(root->right);
    }
};
