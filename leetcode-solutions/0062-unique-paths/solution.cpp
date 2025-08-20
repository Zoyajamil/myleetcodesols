// Problem: Unique Paths (LeetCode 62)
// Link: https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Total steps needed = (m-1) downs + (n-1) rights = m+n-2
        int N = n + m - 2;

        // Choose (m-1) down moves (or equivalently (n-1) right moves)
        int r = m - 1;

        // Use formula for nCr = (N choose r)
        double res = 1;

        // Compute nCr iteratively to avoid overflow
        for (int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }

        // Result must be integer (unique paths count)
        return (int)res;
    }
};

