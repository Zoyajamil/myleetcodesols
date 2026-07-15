class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_r=0;

        for(int &n : nums){
            xor_r= xor_r ^ n;
        }

        int mask = xor_r & (-xor_r);

        int grpa=0;
        int grpb=0;
        for(int n : nums){
            if(mask & n){
                grpa^=n;
            }else{
                grpb^=n;
            }
        }

        return {grpa,grpb};
    }
};
