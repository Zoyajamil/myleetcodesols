class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> res;

        for(auto &p : points){
            int dist=p[0]*p[0] + p[1]*p[1];
            pq.push({dist,p});
        

            if(pq.size() > k ){
                pq.pop();
            }
        }

        while(!pq.empty()){
            res.push_back({pq.top().second});
            pq.pop();
        }
            
        return res;
        }
};
