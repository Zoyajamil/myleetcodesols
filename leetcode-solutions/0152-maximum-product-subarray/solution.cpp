class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int maxproduct=nums[0];
        int minproduct=nums[0];

        for(int i=1;i<nums.size();i++){
            int curr=nums[i];

            if(curr<0) swap(maxproduct,minproduct);

            maxproduct=max(curr,maxproduct * curr);
            minproduct=min(curr,minproduct * curr);

            res=max(res,maxproduct);

        }
        return res;
    }
};
