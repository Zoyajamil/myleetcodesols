class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0;
        int totalcost=0;

        int curgas=0;
        int start=0;

        for(int i=0;i<gas.size();i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
            curgas+=gas[i] - cost[i];

            if(curgas<0){
                start=i+1;
                curgas=0;
            }
        }
        
        if(totalgas<totalcost){
            return -1;
        }
    
    return start;

    }
};
