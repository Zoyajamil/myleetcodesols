class Solution {
private:
    TreeNode* first;      // Stores the first misplaced node
    TreeNode* prev;       // Stores the previously visited node in inorder
    TreeNode* middle;     // Stores the middle node (used if swapped nodes are adjacent)
    TreeNode* last;       // Stores the second misplaced node (if nodes are non-adjacent)

    void inorder(TreeNode* root) {
        if (root == NULL) return;               // No node to process

        inorder(root->left);                    // Visit left subtree first (Inorder)

        // BST inorder should be increasing.
        // If current node is smaller than previous node,
        // then BST property is violated.
        if (prev != NULL && root->val < prev->val) {

            // First time a violation is found
            if (first == NULL) {
                first = prev;                   // Larger node that should come later
                middle = root;                  // Smaller node that should come before
            }

            // Second violation found
            // Update only 'last'
            else {
                last = root;                    // Second misplaced node
            }
        }

        prev = root;                            // Current node becomes previous

        inorder(root->right);                   // Visit right subtree
    }

public:
    void recoverTree(TreeNode* root) {

        first = middle = last = NULL;           // Initially no misplaced nodes

        // Dummy node so the very first comparison never fails.
        // INT_MIN is smaller than every valid BST node value.
        prev = new TreeNode(INT_MIN);

        inorder(root);                          // Detect misplaced nodes

        // If two violations occurred,
        // swapped nodes are far apart (non-adjacent)
        if (first && last)
            swap(first->val, last->val);

        // If only one violation occurred,
        // swapped nodes were adjacent in inorder traversal
        else if (first && middle)
            swap(first->val, middle->val);
    }
};
