// Problem: Majority Element (LeetCode 169)
// Link: https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& v) {

        // size of the given array:
        int n = v.size();
        int cnt = 0; // count
        int el;      // Element

        // Step 1: Boyer-Moore Voting Algorithm
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                // when count is 0, set new element as candidate
                cnt = 1;
                el = v[i];
            }
            else if (el == v[i]) {
                // if current element matches candidate, increase count
                cnt++;
            }
            else {
                // otherwise decrease count
                cnt--;
            }
        }

        // Step 2: Verify if the stored element is majority
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == el) cnt1++;
        }

        // majority element must appear more than n/2 times
        if (cnt1 > (n / 2)) return el;

        return -1; // not a majority (though LeetCode guarantees there is one)
    }
};

