class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0, right=-1;
        int maxlen=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                left=right+1;
                right=i;
            }
            maxlen=max(maxlen,i-left);
        }

        return maxlen;
    }
};
