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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //map: vertical->level->multiset of nodes 
        map<int, map<int, multiset<int>>> nodes;

        //Queue: for BFS (nodes, (vertical,level))
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){

            auto p=q.front();
            q.pop();

            TreeNode* temp=p.first;
            int x=p.second.first;
            int y=p.second.second;

            nodes[x][y].insert(temp->val); //insert value into map

            //left child-x-1,y+1
            //right child x+1,y+1
            if(temp->left){
                q.push({temp->left, {x-1,y+1}});
            }

            if(temp->right){
                q.push({temp->right,{x+1,y+1}});
            }
        }

        //preparing final vector

        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
