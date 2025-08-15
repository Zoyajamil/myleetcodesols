class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;        // Final result
        long long nn = n;        // Copy of n as long long to handle overflow for INT_MIN case

        // If power is negative, convert it to positive for calculation
        if (nn < 0) nn = -1 * nn;

        // Binary exponentiation loop
        while (nn) {
            // If nn is odd, multiply result by current base
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;  // Reduce power by 1 to make it even
            } 
            // If nn is even, square the base and halve the power
            else {
                x = x * x;
                nn = nn / 2;
            }
        }

        // If original n was negative, take reciprocal of result
        if (n < 0) ans = 1.0 / ans;

        return ans;
    }
};

