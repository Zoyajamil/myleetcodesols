class Solution {
private:
    
    void function(int ind,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        ans.push_back(ds);
        for(int i=ind; i< nums.size(); i++){
            if(ind!=i && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            function(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        function(0,nums,ds,ans);
        return ans;
    }
};
