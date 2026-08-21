class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inte, vector<int>& newinte) {
       int n=inte.size();
       vector<vector<int>> res; 
       int i=0;
       
       while( i<n && inte[i][1] < newinte[0]){
                res.push_back(inte[i]);
                i++;
        }

        while(i<n && inte[i][0] <= newinte[1]){
                newinte[0]= min(inte[i][0] , newinte[0]);
                newinte[1]= max(inte[i][1] , newinte[1]);
                i++;
        }

        res.push_back(newinte);

        while(i<n){
                res.push_back(inte[i]);
                i++;
        }
    

       return res;
    }
};
