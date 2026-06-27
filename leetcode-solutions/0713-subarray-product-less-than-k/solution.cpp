class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int n = nums.size();
        int left = 0;
        int product = 1;
        int ans = 0;

        for(int right = 0; right < n; right++) {
            product *= nums[right];

            while(product >= k) {
                product /= nums[left];
                left++;
            }

            ans += (right - left + 1);  //the subarray is not the actual total no of subarrays that can be formed in the window, its the no of subarrays including the num right pointer is at
        }

        return ans;
    }
};
