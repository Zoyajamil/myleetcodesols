class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int> values(n,0);

        for(int num : nums){
            values[num]+=num;
        }

        vector<int> dp(n,0);

        dp[0]=values[0];
        dp[1]= max(values[0], values[1]);

        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], values[i] + dp[i-2]);
        }
    
        return dp[n-1];
    }
};
