class Solution {
private:
    void dfs(int row,int col, vector<vector<char>>& mat,vector<vector<int>>& visited){
        visited[row][col]=1; //assign the zero cube as visited=1 in vis matrix 
        int n=mat.size();//row size
        int m=mat[0].size(); //colsize

        int delrow[]={-1,0,+1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow= row + delrow[i]; //going for the surrounding cubes by using delrow vector
            int ncol= col + delcol[i]; //going for the surrounding cols by using delcol vector

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,mat,visited); //if the visite cube is vali an not visite and its a O, then run dfs further to detect more zeroes 
            }
        }
    }
public:
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));


//starting to traverse in the matrix, if we find a zero, we do DFS search, n find the zeroes connected to the border, if yes- we change them to X


        //checking the first and the last row-> 0,j ||  n-1,j
        for(int j=0;j<m;j++){
            if(!visited[0][j] && mat[0][j]=='O'){ 
                dfs(0,j,mat,visited);
            }
            if(!visited[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,mat,visited);
            }
        }

        //checking the first and the last col-> i,0 || i,m-1
        for(int i=0;i<n;i++){
            if(!visited[i][0] && mat[i][0]=='O'){
                dfs(i,0,mat,visited);
            }
            if(!visited[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,mat,visited);
            }
        }


        //Traversing the whole matrix = if a zero is not visited- means it is not reached by a zero from the border, so we will convert it to X 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
    }
};
