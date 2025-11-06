// LeetCode: Find First and Last Position of Element in Sorted Array
#include <vector>
using namespace std;

class Solution {
    int firstPos(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) { ans = m; r = m - 1; }
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
    int lastPos(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) { ans = m; l = m + 1; }
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return { firstPos(nums, target), lastPos(nums, target) };
    }
};

