class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start=0;
        unordered_map<int,int> mpp;
        int sum=0;
        int maxsum=0;

        for(int end=0; end<nums.size() ; end++){
           
            mpp[nums[end]]++;
            sum+=nums[end];

           while(mpp[nums[end]] > 1){
                mpp[nums[start]]--;
                sum-=nums[start];
                start++;
           }
            
        maxsum= max(maxsum, sum);
        }
        return maxsum;     
    }
};
