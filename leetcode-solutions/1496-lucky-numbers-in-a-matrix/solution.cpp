class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<int> rowMin;
        vector<int> colMax;
        vector<int> luckyno;


        for(int i=0;i<n;i++){
            int rowmin=INT_MAX;
            for(int j=0;j<m ; j++){
                rowmin=min(rowmin , mat[i][j]);
            }
            rowMin.push_back(rowmin);
        }

        for(int j=0;j<m;j++){
            int colmax=INT_MIN;
            for(int i=0;i<n;i++){
                colmax=max(colmax , mat[i][j]);
            }
            colMax.push_back(colmax);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==rowMin[i] && mat[i][j]==colMax[j]){
                    luckyno.push_back(mat[i][j]);
                }
            }
        }
        return luckyno;        
    }
};
