class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;               // Stores the final answer

        // Check every bit position (0 to 31)
        for(int k = 0; k < 32; k++) {
            int temp = 1 << k;        // Mask with only kth bit set

            int cntone = 0;           // Count numbers having kth bit = 1
            int cntzero=0;
            // Traverse every number
            for(int n : nums) {

                // Is kth bit set?
                if((n & temp)!=0){
                    cntone++;
                }else{
                    cntzero++;
                }
            }

            // If remainder is 1, unique number has this bit set
            if(cntone % 3 == 1)
                result |= temp;
        }

        return result;
    }
};
