class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> res;

        for(int i=1;i<=nums.size();i++){
            if(set.find(i)==set.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};
