class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int prefixsum=0; 
        int count=0;
        mpp[0]=1;

        int n=nums.size();

        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            int remove=prefixsum-k;
            count+=mpp[remove];
            mpp[prefixsum]+=1;
            
        }
        return count;
    }
};
