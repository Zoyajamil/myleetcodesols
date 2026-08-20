class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        res[0]=nums[0];
        int prefixsum= nums[0];

        for(int i=1;i<n;i++){
            prefixsum+=nums[i];
            res[i]=prefixsum;
        }
        return res;
    }
};
