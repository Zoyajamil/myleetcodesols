class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> result;

        for(int n : nums){
            mpp[n]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto it : mpp){
            pq.push({it.second, it.first}); //push in pq acc to the frequency of ele (it.second)
        }

        while(k-- > 0){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;

    }
};
