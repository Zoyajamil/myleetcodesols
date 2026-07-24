class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        vector<vector<int>> result(n,vector<int>(m,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    result[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            pair<int,int> p= q.front();
            q.pop();
            int row=p.first;
            int col=p.second;

            for(int i=0;i<4;i++){
                int nrow=row + delrow[i];
                int ncol= col + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && result[nrow][ncol]==-1){
                    result[nrow][ncol] = result[row][col] +1;
                    q.push({nrow,ncol});
                }
            }
        }

        return result;
    }
 
};
