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
//Define the TreeNode structure


/*class Solution {
public:

// Function to perform inorder traversal
// of a binary tree iteratively
vector<int> inorderTraversal(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* node = root;
    vector<int> inorder;


    while(true){
        // If the current node is not NULL
        if(node != NULL){
            // Push the current
            // node to the stack
            st.push(node);
            // Move to the left child
            // of the current node
            node = node->left;
        }
        else{
            // If the stack is empty,
            // break the loop
            if(st.empty()){
                break;
            }
            
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    // Return the inorder
    // traversal result
    return inorder;
}

};*/

#include <vector>
using namespace std;

class Solution{
public:

    vector<int> inorderTraversal(TreeNode* root){
    
    vector<int> inorder;
    TreeNode* cur = root;

    while(cur!=NULL){

        //case 1 no left child
        if(cur->left ==NULL){
            inorder.push_back(cur->val);
            cur=cur->right;
        }

        else{
            //find inorder predecessor
            TreeNode* prev=cur->left;


            while(prev->right!=NULL && prev->right!=cur){
                prev=prev->right;
            }

            //make temporary thread
            if(prev->right==NULL){
                prev->right=cur;
                cur=cur->left;
            }

            else{
                //remove thread 
                prev->right=NULL;
                inorder.push_back(cur->val);
                cur=cur->right;
            }

        }
    }

    return inorder;
    }

};


