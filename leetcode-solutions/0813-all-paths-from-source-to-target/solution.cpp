class Solution {
public:

    void dfs(int node,vector<vector<int>>& graph,vector<int>& path,vector<vector<int>>& ans){
        path.push_back(node); //add current node to path

        //if reached target node
        if(node==graph.size()-1){
            ans.push_back(path);  //store path
        }
        else{
            //explore all neighbors

            for(int neighbor:graph[node]){
                dfs(neighbor,graph,path,ans);
            }
        }

        path.pop_back();
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        vector<int> path;

        dfs(0,graph,path,ans);

        return ans;
    }
};
