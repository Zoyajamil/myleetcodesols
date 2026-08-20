class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int oneCount = 0;
        int zeroToOnes = 0;

        int i = 0;

        // Skip starting 0s
        while(i < s.length() && s[i] == '0') {
            i++;
        }

        for(; i < s.length(); i++) {

            if(s[i] == '0') {
                // Flip 0 -> 1
                zeroToOnes++;
            }
            else {
                // Count 1s
                oneCount++;
            }

            // Choose the minimum flips:
            // either flip the 0s to 1s
            // or flip the previous 1s to 0s
            zeroToOnes = min(zeroToOnes, oneCount);
        }

        return zeroToOnes;
    }
};
