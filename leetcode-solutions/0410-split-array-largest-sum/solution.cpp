class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        //search space is the maximum sum possible for a subarray, it starts from the largest element in the array to the entire sum of the array
        int n=nums.size();
        int low= *max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;

        while(low<=high){
            int mid= (low+high) >> 1;

            if(subarray(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }

    bool subarray(vector<int> &nums, int maxsum,int k){
        int cnt=1;
        int sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxsum){
                cnt++;
                sum=nums[i];
                if(cnt>k) return false;
            }
        }

        return true;
    }
};
