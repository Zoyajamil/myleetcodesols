class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        
        int count=0;
        int n=intervals.size();
        int lastendtime=intervals[0][1];

        for(int i =1; i< n ; i++){
            if(intervals[i][0]<lastendtime){
                count++;
            }else{
                lastendtime=intervals[i][1];
            }
        }

        return count;
    }
};
