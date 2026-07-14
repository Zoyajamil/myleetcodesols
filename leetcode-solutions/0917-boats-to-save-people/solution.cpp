class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt=0;
        //int sum=0;
        sort(people.begin(),people.end());

        int left=0;
        int right=people.size()-1;

        while(left<=right){
            int sum=people[left] + people[right];
            if(sum<=limit){
                cnt++;
                left++;
                right--;
            }else{
                cnt++;
                right--;
            }
        }
    return cnt;

    }
};

//simple 2 pointer approach //left and right weight is added ie, the heaciest n lighest are paired n checked if exceed the limit, if yes cnt is increased and right pointer is decreased 
//if no, both the pointers are moved and boat cnt is increased as the wieght sum is less then limit 
