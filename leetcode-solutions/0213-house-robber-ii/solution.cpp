class Solution {
public:
    int helpr(vector<int>& nums, int start, int end) {
        int n=nums.size();
        vector<int> dp(n-1);

        dp[0]=nums[start];
        dp[1]= max(nums[start], nums[start+1]);

        for(int i=start+2 , j=2; i<=end ;i++, j++){
            dp[j]= max(nums[i]+ dp[j-2] , dp[j-1]);
        }

        return dp[n-2];
    }

    int rob(vector<int>& nums){
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0] , nums[1]);
        return max(helpr(nums, 0 , n-2) , helpr(nums,1,n-1));
    }

};
