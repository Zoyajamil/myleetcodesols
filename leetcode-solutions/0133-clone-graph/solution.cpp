/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private: 
    unordered_map<Node*,Node*>mp;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        if(mp.find(node)!=mp.end()) //if already cloned return from map
            return mp[node];
        
        Node* cloneNode=new Node(node->val); //create clone of current node

        mp[node]= cloneNode; //store mapping

        //recursively clone all the neighbours 
        for(auto neighbor :node->neighbors){
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};
