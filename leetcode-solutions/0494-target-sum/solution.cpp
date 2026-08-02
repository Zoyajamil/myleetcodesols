class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        // Calculate the total sum of all elements
        int S = accumulate(nums.begin(), nums.end(), 0);

        // If target is impossible to achieve, return 0
        // 1. Target cannot be greater than total sum
        // 2. (S - target) must be even to form a valid subset sum
        if (S < abs(target) || (S - target) % 2 != 0)
            return 0;

        // Convert the problem into:
        // Count subsets having sum = (S - target) / 2
        int x = (S - target) / 2;

        // dp[j] = number of ways to make sum j
        vector<int> dp(x + 1, 0);

        // There is exactly one way to make sum 0
        // (choose no elements)
        dp[0] = 1;

        // Process every number one by one
        for (int num : nums) {

            // Traverse backwards because each number
            // can be used only once
            for (int j = x; j >= num; j--) {

                // Current ways =
                // existing ways +
                // ways after including current number
                dp[j] += dp[j - num];
            }
        }

        // Number of subsets having required sum
        return dp[x];
    }
};
