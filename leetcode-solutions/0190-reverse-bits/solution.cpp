class Solution {
public:
    int reverseBits(int n) {
        int res=0;
        for(int i=0;i<32;i++){
            int RightMostBit= (n&1);  //and to take out the rightmostbit
            n=n >> 1; // shift n towards right to get the next right bit
            res= res << 1; //
            res= res | RightMostBit;
        }
        return res;
    }
};
