class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto &p : prerequisites){
            int course=p[0];
            int prereq=p[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count=0;
        vector<int> res;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            count++;

        for(auto &neighbour : adj[node]){
            indegree[neighbour]--;
        

            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

        if(count==numCourses){
            return res;
        }else{
            return {};
        }
    }
};
