class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        map<pair<int,int>, unordered_set<char>> square;

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c] == '.'){
                    continue;
                }

                char num=board[r][c];

                if(rows[r].count(num) ||
                cols[c].count(num)||
                square[{r/3 , c/3}].count(num)){
                    return false;
                }

                rows[r].insert(num);
                cols[c].insert(num);
                square[{r/3,c/3}].insert(num);

            }
        }
        return true;
    }
};
