class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0; int high=nums.size()-1;
        
        int ans=INT_MAX;

        while(low<=high){

            int mid=low+(high-low)/2;

            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                if(nums[mid]<=ans){
                    ans=min(ans,nums[mid]);
                    high=mid-1;
                }
            }
        }

        return ans;
    }
};



//nums = [4, 5, 6, 7, 0, 1, 2]
