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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum,0,path,res);
        return res;
    }
    
    void dfs(TreeNode* node,int targetSum,int cursum,vector<int>& path,vector<vector<int>>& res){
        if(!node) return;

        cursum+=node->val; //add the root value to the sum and the path 
        path.push_back(node->val);

        if(!node->left && !node->right && cursum==targetSum){ //if its a leaf node n target sum achieved we push the path to the final result vector 
            res.push_back(path);
        }

        dfs(node->left,targetSum,cursum,path,res);
        dfs(node->right,targetSum,cursum,path,res);

        path.pop_back(); //after getting a acceptable path we have to backtrack from the leaf node to the root 
        //while backtracking we have to keep removing the current element we are at and go back 
    }
};
