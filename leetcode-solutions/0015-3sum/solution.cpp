// LeetCode: 3Sum

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;      // This will store all unique triplets
        sort(nums.begin(), nums.end()); // Step 1: Sort array to make duplicate handling + 2-pointer possible
        int n = nums.size();

        // Loop for first element of the triplet
        for (int i = 0; i < n - 2; ++i) {

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;     // Left pointer
            int r = n - 1;     // Right pointer

            // Now use 2-pointer technique to find pairs that sum to -nums[i]
            while (l < r) {

                long sum = (long)nums[i] + nums[l] + nums[r];  
                // Long used to avoid integer overflow

                if (sum == 0) {
                    // Found a valid triplet
                    res.push_back({nums[i], nums[l], nums[r]});

                    // Skip duplicates for the second element
                    while (l < r && nums[l] == nums[l + 1])
                        ++l;

                    // Skip duplicates for the third element
                    while (l < r && nums[r] == nums[r - 1])
                        --r;

                    // Move both pointers to find new pairs
                    ++l;
                    --r;
                }

                else if (sum < 0) {
                    // Sum is too small → increase it by moving left pointer to right
                    ++l;
                }

                else {
                    // Sum is too large → decrease it by moving right pointer to left
                    --r;
                }
            }
        }
        return res;   // Return all unique triplets
    }
};

