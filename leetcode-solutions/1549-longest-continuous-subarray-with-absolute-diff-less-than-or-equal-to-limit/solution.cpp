// LeetCode: Longest Continuous Subarray With Absolute Diff >= Limit
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd, mind;
        int left = 0, ans = 0;
        for (int right = 0; right < (int)nums.size(); ++right) {
            while (!maxd.empty() && nums[right] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && nums[right] < mind.back()) mind.pop_back();
            maxd.push_back(nums[right]);
            mind.push_back(nums[right]);

            while (!maxd.empty() && !mind.empty() &&
                   maxd.front() - mind.front() > limit) {
                if (nums[left] == maxd.front()) maxd.pop_front();
                if (nums[left] == mind.front()) mind.pop_front();
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

