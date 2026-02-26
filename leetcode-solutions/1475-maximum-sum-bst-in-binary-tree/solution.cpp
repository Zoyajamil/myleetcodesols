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

class Nodevalue{
public:
    int minnode, maxnode, sum;

    Nodevalue(int minnode, int maxnode, int sum){
        this->minnode = minnode;
        this->maxnode = maxnode;
        this->sum = sum;
    }
};

class Solution{
private:
    int maxSum = 0;

    Nodevalue helper(TreeNode* root){

        // empty tree is valid BST with sum 0
        if(!root){
            return Nodevalue(INT_MAX, INT_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // check BST condition
        if(left.maxnode < root->val && root->val < right.minnode){

            int currSum = left.sum + right.sum + root->val;

            maxSum = max(maxSum, currSum);

            return Nodevalue(
                min(root->val, left.minnode),
                max(root->val, right.maxnode),
                currSum
            );
        }

        // not a BST
        return Nodevalue(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
