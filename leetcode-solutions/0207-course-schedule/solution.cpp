class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //adjacencylist
        vector<vector<int>> adj(numCourses);

        //indegree array
        vector<int> indegree(numCourses,0);

        //build graph
        for(auto &p : prerequisites){
            int course=p[0];
            int prereq=p[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses ;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;

            for(auto neighbor : adj[node]){
                indegree[neighbor]--;

                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }

        return count==numCourses;
    }
};
