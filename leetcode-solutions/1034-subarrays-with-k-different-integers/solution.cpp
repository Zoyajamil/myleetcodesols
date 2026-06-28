class Solution {
public:

    int atmost(vector<int> nums, int k){
        int left=0;
        int ans=0;
        unordered_map<int,int> mpp;
        int n=nums.size();

        if(k<0) return 0;

        for(int right=0;right<n;right++){
            mpp[nums[right]]++;

            while(mpp.size()>k){
                mpp[nums[left]]--;

                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }

            ans+= right-left+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};
