class Solution {
public:
    void backtrack(int index, int target,
                   vector<int>& candidates,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // if target becomes 0, store the combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // if index is out of bounds or target is negative
        if (index == candidates.size() || target < 0)
            return;

        // pick the current element (can be reused)
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            backtrack(index, target - candidates[index],
                      candidates, current, result);
            current.pop_back(); // backtrack
        }

        // skip the current element
        backtrack(index + 1, target,
                  candidates, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, target, candidates, current, result);
        return result;
    }
};

