class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int pre = 1, suff = 1;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {

            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;

           
            pre *= nums[i];
            suff *= nums[n - i - 1];


            ans = max(ans, max(pre, suff));
        }

        return ans;
    }
};



/*class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            // If negative, swap because sign flips
            if (curr < 0) {
                swap(maxProd, minProd);
            }

            // Update max and min product ending here
            maxProd = max(curr, maxProd * curr);
            minProd = min(curr, minProd * curr);

            // Update global maximum
            res = max(res, maxProd);
        }

        return res;
    }
};*/
