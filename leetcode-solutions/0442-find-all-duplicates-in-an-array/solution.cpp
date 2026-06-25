class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> res;
        for (int n : nums){
            n=abs(n);
            if(nums[n-1]<0){
                res.push_back(n); //mapping the number to an index less than it to negative
            }
            nums[n-1]*=-1;
        }
       
       return res;
    }
};

// arr= 1 2 3 4 indexes- 0 1 2 3 
//so our arr 3 3 2 2 is mapped like 3 is mapped to the index 2, index 2 is changed to negative, now when we reach 3 again we again map to index 2 and see that it is negative, means already visited, so we append it to result and make it change its sign again 
