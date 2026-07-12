class Solution {
public:

    // Generate all permutations starting from index i
    void perms(int i, vector<vector<int>>& res, vector<int>& nums) {

        // Base case:
        // If every position has been fixed,
        // we have one complete permutation.
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        // Try placing every remaining element
        // at position i.
        for (int j = i; j < nums.size(); j++) {

            // Choose:
            // Put nums[j] at position i.
            swap(nums[i], nums[j]);

            // Recurse to fix the next position.
            perms(i + 1, res, nums);

            // Backtrack:
            // Restore the original array for the next choice.
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> res;

        perms(0, res, nums);

        return res;
    }
};
