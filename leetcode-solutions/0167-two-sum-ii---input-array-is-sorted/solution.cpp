class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {

            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                // LeetCode expects 1-based indexing
                return {left + 1, right + 1};
            }
            else if (sum < target) {
                left++;     // Need a larger sum
            }
            else {
                right--;    // Need a smaller sum
            }
        }

        return {};
    }
};
