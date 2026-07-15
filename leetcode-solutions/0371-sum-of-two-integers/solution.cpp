class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int xor_r= a ^ b;
            int carry= (a & b) << 1;
            a=xor_r;
            b=carry;

        }
        return a;
    }
};
