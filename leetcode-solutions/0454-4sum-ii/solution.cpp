class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        
        unordered_map<int,int> mpp;
        mpp.reserve(nums3.size() * nums4.size());

        for(int a : nums1){
            for(int b : nums2){
                mpp[a+b]++;
            }
        }
        
        int ans=0;

        for(int c : nums3){
            for(int d : nums4){
                int sum= c + d;
            

                if(mpp.find(-sum) != mpp.end()){
                    ans+=mpp[-sum]; 
                }
            }
        }
        return ans;
    }
};
