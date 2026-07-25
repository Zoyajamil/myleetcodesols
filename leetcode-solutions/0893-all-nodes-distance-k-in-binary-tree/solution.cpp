/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // adj[v] = neighbors of node value v, once tree is treated as an undirected graph
    vector<vector<int>> adj = vector<vector<int>>(501);
    vector<int> ans;                      // final result: values at distance k
    vector<int> vis = vector<int>(501, 0); // tracks visited node values

    // BFS outward from target, layer by layer, until we reach distance k
    void bfs(TreeNode* target, int k) {
        for (int i = 0; i < 501; i++) vis[i] = 0; // reset visited state

        queue<int> q;
        int dist = 0; // current BFS layer = distance from target
        q.push(target->val);
        vis[target->val] = 1;

        while (!q.empty()) {
            int n = q.size(); // number of nodes in this layer

            if (dist == k) {
                // every node currently in the queue is exactly distance k away
                while (!q.empty()) {
                    ans.push_back(q.front());
                    q.pop();
                }
                return;
            } else {
                // process this layer, enqueue unvisited neighbors for next layer
                while (n--) {
                    int node = q.front();
                    q.pop();
                    vis[node] = 1;
                    for (int i : adj[node]) {
                        if (!vis[i]) {
                            vis[i] = 1;
                            q.push(i);
                        }
                    }
                }
            }
            dist++; // advance to next layer
        }
        // if we exit the loop without dist == k, k was too far -> ans stays empty
    }

    // recursively builds an undirected graph from the tree
    // (add edge in both directions so we can move toward ancestors too)
    void build(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            build(root->left);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            build(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root);    // convert tree into graph
        bfs(target, k);  // BFS from target to collect nodes at distance k
        return ans;
    }
};
