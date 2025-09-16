class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  // Edge case: empty array

        int longest = 1;                   // store the length of the longest sequence
        unordered_set<int> st;             // to store unique numbers for O(1) lookups

        // Step 1: Insert all numbers into the hash set
        for (int num : nums) {
            st.insert(num);
        }

        // Step 2: Iterate through the set to find sequences
        for (int num : st) {
            // Check if this number is the start of a sequence
            if (st.find(num - 1) == st.end()) {
                int current = num;
                int count = 1;

                // Count consecutive numbers starting from 'current'
                while (st.find(current + 1) != st.end()) {
                    current += 1;
                    count += 1;
                }

                // Update longest sequence length
                longest = max(longest, count);
            }
        }

        return longest;
    }
};

