class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inte) {
        sort(inte.begin() , inte.end() , [](vector<int> &a, vector<int> &b){
            if(a[0] != b[0]){
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int count=0;
        int maxend=0;
        
        for(int i=0; i<inte.size() ; i++){
            int start= inte[i][0];
            int end= inte[i][1];

            if(end <= maxend){
                count++;
            }

            maxend = max(maxend, end); 
        }
        return inte.size()- count; 
    }
};
