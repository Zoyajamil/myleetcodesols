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


class BSTIterator{
private:
    stack<TreeNode*> st;
    bool reverse;
    void pushall(TreeNode* node){
        while(node){
            st.push(node);
            if(reverse)
                node=node->right;
            else
                node=node->left;
        }
    }

public:

    BSTIterator(TreeNode* root,bool isReverse){
        reverse = isReverse;
        pushall(root);
    }

    int next(){
        TreeNode* node=st.top();
        st.pop();

        if(!reverse)
            pushall(node->right);
        else
            pushall(node->left);
        
        return node->val;
    }

    bool hasnext(){
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator left(root,false); //smallest to largest
        BSTIterator right(root,true); //largest to smallest

        int i=left.next();
        int j=right.next();

        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k){
                if(left.hasnext())
                    i=left.next();
                else
                return false;
            }
            else{
                if(right.hasnext())
                    j=right.next();
                else
                return false;
            }
        }

        return false;
    }
};
