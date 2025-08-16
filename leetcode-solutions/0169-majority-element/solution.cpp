class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Step 1: Find the size of the input array
        int n = nums.size();

        // Step 2: Create a map to count frequencies of elements
        map<int, int> mpp;

        // Step 3: Loop through the array and count each element
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;  // increment the count of nums[i]
        }

        // Step 4: Check the map for an element whose count > n/2
        for (auto it : mpp) {
            if (it.second > n / 2) {
                return it.first;  // return the majority element
            }
        }

        // Step 5: If no majority element exists (the problem guarantees one),
        // we can return -1, but this line will never be executed on LeetCode.
        return -1;
    }
};

