class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // A large value representing an impossible state
        int INF = amount + 1;

        // dp[j] = minimum coins required to make amount j
        vector<int> dp(amount + 1, INF);

        // 0 coins are needed to make amount 0
        dp[0] = 0;

        // Process every coin
        for (int coin : coins) {

            // Traverse forward because
            // one coin can be used multiple times
            for (int j = coin; j <= amount; j++) {

                // Either:
                // 1. Keep previous answer
                // 2. Take current coin once and
                //    solve the remaining amount
                dp[j] = min(dp[j], 1 + dp[j - coin]);
            }
        }

        // If amount is still impossible, return -1
        if (dp[amount] == INF)
            return -1;

        // Otherwise return minimum coins needed
        return dp[amount];
    }
};
