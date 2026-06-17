class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        // DP arrays for max and min product ending at i
        vector<int> dpMax(n);
        vector<int> dpMin(n);

        // Base case
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];

        // Store final answer
        int ans = nums[0];

        for (int i = 1; i < n; i++) {

            // Max product ending at i
            dpMax[i] = max({
                nums[i],                    // start new subarray
                nums[i] * dpMax[i - 1],     // extend max product
                nums[i] * dpMin[i - 1]      // extend min product
            });

            // Min product ending at i
            dpMin[i] = min({
                nums[i],                    // start new subarray
                nums[i] * dpMax[i - 1],     // extend max product
                nums[i] * dpMin[i - 1]      // extend min product
            });

            // Update overall maximum
            ans = max(ans, dpMax[i]);
        }

        return ans;
    }
};
