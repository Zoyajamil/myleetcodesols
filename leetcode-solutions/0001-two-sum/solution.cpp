class Solution {
public:
    // Function to return indices of the two numbers such that they add up to the target
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store numbers and their indices
        unordered_map<int, int> mp;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // the required number to form the target

            // If complement already exists in map, we found the answer
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i}; // return stored index and current index
            }

            // Otherwise, store current number with its index
            mp[nums[i]] = i;
        }

        // If no solution is found (though problem guarantees one), return empty vector
        return {};
    }
};

