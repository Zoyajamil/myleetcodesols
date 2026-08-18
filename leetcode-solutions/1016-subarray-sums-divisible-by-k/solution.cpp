class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int prefixsum=0;
        unordered_map<int,int> mpp;
        int n =nums.size();
        mpp[0]=1;

        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            int remove=prefixsum % k;

            if(remove < 0){
                remove+=k;
            }

            if(mpp.find(remove) != mpp.end()){
                count+=mpp[remove];
                mpp[remove]+=1;
            }else{
                mpp[remove]=1;
            }

        }
        return count;

    }
};
