class NumArray {
public:
    vector<int> prefixsum;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefixsum.resize(n+1);
        prefixsum[0]=0;

        for(int i=1;i<=n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixsum[right+1] -prefixsum[left];
   
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
