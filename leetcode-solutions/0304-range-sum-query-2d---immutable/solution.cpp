class NumMatrix {
private:
    int row, col;
    vector<vector<int>> sums;

public:
    NumMatrix(vector<vector<int>> &matrix) {

        // Number of rows and columns
        row = matrix.size();
        col = row > 0 ? matrix[0].size() : 0;

        // Create a (row+1) x (col+1) prefix sum matrix.
        // The extra row and column of 0s help avoid boundary checks.
        sums = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));

        // Build the 2D prefix sum matrix.
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {

                /*
                    sums[i][j] stores the sum of all elements
                    from matrix[0][0] to matrix[i-1][j-1].

                    Formula:

                    Current Cell
                    + Top Prefix
                    + Left Prefix
                    - Top-Left Prefix (counted twice)

                    sums[i][j] =
                        matrix[i-1][j-1]
                      + sums[i-1][j]
                      + sums[i][j-1]
                      - sums[i-1][j-1];
                */

                sums[i][j] = matrix[i-1][j-1]
                           + sums[i-1][j]
                           + sums[i][j-1]
                           - sums[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        /*
            We want the sum inside this rectangle.

                 col1        col2
                   |-----------|
            row1 --+-----------+
                  |           |
                  | Rectangle |
                  |           |
            row2 --+-----------+

            Start with the large rectangle:
                sums[row2+1][col2+1]

            Remove:
                - Area above
                - Area left

            The top-left area gets removed twice,
            so add it back once.

            Inclusion-Exclusion Principle.
        */

        return sums[row2 + 1][col2 + 1]
             - sums[row2 + 1][col1]
             - sums[row1][col2 + 1]
             + sums[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
