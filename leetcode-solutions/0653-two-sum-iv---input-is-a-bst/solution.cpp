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


/*class Solution {
public:
    unordered_set<int> st;

    bool findTarget(TreeNode* root, int k) {
        // Base case: null node
        if (root == NULL) return false;

        // If complement is found, return true
        if (st.count(k - root->val)) return true;

        // Otherwise, add current node value to the set
        st.insert(root->val);

        // Recurse on left and right subtrees
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};*/


//Another approach - Do inorder traversal and then use two pointers left and right like standard two sum and check

//Most optimal approach is using a BST Iterator with functions next() and before()


class BSTIterator{
    stack<TreeNode*> mystack;
    //using reverse as a flag
    //reverse ->true->before
    //reverse->false->next
    bool reverse=true;
public: 
    BSTIterator(TreeNode *root, bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }

    //return whether we have next smallest number or not 
    bool hasnext(){
        return !mystack.empty();
    }

    //return the next smallest number
    int next(){
        TreeNode *tempnode=mystack.top();
        mystack.pop();
        if(!reverse) pushAll(tempnode->right);
        else pushAll(tempnode->left);
        return tempnode->val;
    }

private: 
    void pushAll(TreeNode *node){
        for(;node!=NULL;){
            mystack.push(node);
            if(reverse==true){
                node=node->right;
            }else{
                node=node->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        //next
        BSTIterator l(root,false);
        //for before
        BSTIterator r(root,true);

        int i =l.next();
        int j =r.next();

        while(i<j){
            if(i+j==k) return true;
            else if(i+j <k) i=l.next();
            else j=r.next();
        }

        return false;
    }
};


