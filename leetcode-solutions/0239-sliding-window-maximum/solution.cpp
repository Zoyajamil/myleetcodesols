/*class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;        // stores indices
        vector<int> result;  // stores answers

        for (int i = 0; i < nums.size(); i++) {

            // Remove indices out of current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Start adding results after first window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
*/

class Solution  {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums,int k){
            deque<int> dq;
            vector<int> result;

            for(int i=0;i< nums.size();i++){

                //Remove indices out of current window
                if(!dq.empty() && dq.front()<=i-k){
                    dq.pop_front();
                }

                //Maintain decreasing order in dequeue
                while(!dq.empty() && nums[dq.back()] < nums[i]){
                    dq.pop_back();
                }

                dq.push_back(i);

                //Start adding results after first window
                if(i>=k-1){
                    result.push_back(nums[dq.front()]);
                }
            }
            return result;
        }
};
