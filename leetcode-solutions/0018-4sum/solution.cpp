class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(); // size of array
        vector<vector<int>> ans;

        // Step 1: Sort the array to use two-pointer approach
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first two numbers using i and j
        for (int i = 0; i < n; i++) {
            // Skip duplicate elements for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                // Skip duplicate elements for j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Step 3: Use two pointers for the remaining two numbers
                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    // Use long long to prevent integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        // Found a valid quadruplet
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        // Skip duplicates for k and l
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if (sum < target) {
                        k++; // need a bigger sum
                    }
                    else {
                        l--; // need a smaller sum
                    }
                }
            }
        }

        return ans;
    }
};

