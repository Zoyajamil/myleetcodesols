class Solution {
public:
    // vector<vector<int>> dp;
    // bool solve(vector<int>& nums,int target, int i, int currsum){
    //     if(currsum==target)return true;
    //     if(currsum > target || i==nums.size()) return false;

    //     if(dp[i][currsum] != -1) return dp[i][currsum];

    //     return dp[i][currsum] =
    //         solve(nums,target,i+1,currsum+nums[i]) ||
    //         solve(nums,target,i+1,currsum);
    // }
   
    bool canPartition(vector<int>& nums) {
        // int n=nums.size();
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        // }
        // if(sum%2)return false;

        // dp.assign(nums.size(), vector<int>(sum/2+1,-1));

        // return solve(nums,sum/2,0,0);

        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2)return false;
        int target=sum/2;

        vector<int>dp(target+1,false);
        dp[0]=true;

        for(int num:nums){
            for(int j=target;j>=num;j--){
                dp[j] = dp[j] || dp[j-num];
            }
        }

        return dp[target];


        
        
    }
    
};
