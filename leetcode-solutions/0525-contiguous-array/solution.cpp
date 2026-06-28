class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        // Running prefix sum
        // Treat:
        // 1 as +1
        // 0 as -1
        int sum = 0;

        // Stores the maximum length found so far
        int maxLen = 0;

        /*
            Map stores:
            prefixSum -> first index where this sum occurred

            Initialize:
            sum = 0 at index -1

            This helps handle subarrays starting from index 0.
        */
        unordered_map<int, int> seen{{0, -1}};

        for(int i = 0; i < nums.size(); i++) {

            // Convert:
            // 1 -> +1
            // 0 -> -1
            sum += (nums[i] == 1) ? 1 : -1;

            /*
                If we've seen this prefix sum before,
                then the subarray between the previous index + 1
                and the current index has equal numbers of
                0s and 1s.
            */
            if(seen.count(sum))
                maxLen = max(maxLen, i - seen[sum]);

            // Store only the first occurrence,
            // because it gives the longest possible subarray.
            else
                seen[sum] = i;
        }

        return maxLen;
    }
};
