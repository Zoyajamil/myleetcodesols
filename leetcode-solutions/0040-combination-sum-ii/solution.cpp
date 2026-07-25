class Solution {
public:
    vector<vector<int>> ans; // stores all valid combinations

    // backtracking helper: builds combinations summing to tar, starting from index idx
    void sol(vector<int>& temp, vector<int>& nums, int tar, int idx) {
        if (tar == 0) {
            ans.push_back(temp); // found a valid combination
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i-1]) continue; // skip duplicates at same tree level
            if (nums[i] > tar) break;                       // sorted array, no point going further

            temp.push_back(nums[i]);
            sol(temp, nums, tar - nums[i], i + 1); // move to i+1, each number used once
            temp.pop_back();                        // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); // sort so duplicates are adjacent, enables pruning

        sol(temp, candidates, target, 0);
        return ans;
    }
};
