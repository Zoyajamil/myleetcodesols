class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> mpp;

        for(int m : nums1){
            mpp[m]++;
        }

        for(int i=0;i<nums2.size();i++){
            if(mpp.find(nums2[i]) != mpp.end() && mpp[nums2[i]] > 0 ){
                res.push_back(nums2[i]);
                mpp[nums2[i]]=0;
            }
        }
        return res;
    }
};
