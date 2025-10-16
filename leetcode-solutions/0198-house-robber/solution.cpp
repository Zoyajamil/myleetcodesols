// S5. DP Iterative (Bottom-up / Tabulation) version
// Time: O(n), Space: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> f1tbl(1 + nums.size());   // DP table of size (n + 1)
        f1tbl[0] = 0;                         // Base case: no house → 0 money
        f1tbl[1] = nums[0];                   // Base case: one house → rob it

        // Fill DP table from 2 to n
        for (int n = 2; n <= nums.size(); n++) {
            // Either skip current house (f1tbl[n-1])
            // or rob it (nums[n-1] + f1tbl[n-2])
            f1tbl[n] = max(f1tbl[n - 1], nums[n - 1] + f1tbl[n - 2]);
        }

        return f1tbl[nums.size()];            // Last element holds the max amount
    }
};

