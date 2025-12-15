#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;    // current consecutive 1s count
        int maxi = 0;   // maximum consecutive 1s

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                cnt++;
            else
                cnt = 0;

            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

