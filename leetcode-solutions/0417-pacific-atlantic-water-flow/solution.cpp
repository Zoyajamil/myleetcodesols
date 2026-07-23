class Solution {

private:
    void dfs(int row,int col,vector<vector<int>>& mat,  vector<vector<int>>& visited){
        visited[row][col] =1;
        int n=mat.size();
        int m=mat[0].size();

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow= row + delrow[i];
            int ncol= col + delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && mat[nrow][ncol] >= mat[row][col]){
                dfs(nrow,ncol,mat,visited);
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> res;

        //pacific ocean- first row
        //atlantic- last row 
        for(int j=0;j<m;j++){
            if(!pacific[0][j]){
                dfs(0,j,mat,pacific);
            }

            if(!atlantic[n-1][j]){
                dfs(n-1,j,mat,atlantic);
            }
        }
        
        //pacific= first column 
        //atlantic= last column
        for(int i=0;i<n;i++){
            if(!pacific[i][0]){
                dfs(i,0,mat,pacific);
            }

            if(!atlantic[i][m-1]){
                dfs(i,m-1,mat,atlantic);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
