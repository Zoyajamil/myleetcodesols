class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        vector<int> leftrow(n,0);
        vector<int> lowerdiagnol(2*n-1,0);
        vector<int> upperdiagnol(2*n-1,0);
        solve(0,board,ans,leftrow,lowerdiagnol,upperdiagnol,n);
        return ans;
    }

public: 
    void solve(int col, vector<string> &board,vector<vector<string>> &ans,vector<int> &leftrow,
    vector<int> &lowerdiagnol, vector<int> &upperdiagnol,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerdiagnol[row+col]==0 && upperdiagnol[n-1 + col-row]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiagnol[row+col]=1;
                upperdiagnol[n-1 + col-row]=1;
                solve(col+1,board,ans,leftrow,lowerdiagnol,upperdiagnol,n);
                //backtrack
                board[row][col]='.';
                leftrow[row]=0;
                lowerdiagnol[row+col]=0;
                upperdiagnol[n-1+col-row]=0;
            }
        }    
    }
};
