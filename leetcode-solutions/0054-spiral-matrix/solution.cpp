class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowbegin = 0;
        int colbegin = 0;
        int rowend = matrix.size() - 1;
        int colend = matrix[0].size() - 1;

        vector<int> result;

        while (rowbegin <= rowend && colbegin <= colend) {

            // Traverse right
            for (int j = colbegin; j <= colend; j++) {
                result.push_back(matrix[rowbegin][j]);
            }
            rowbegin++;

            // Traverse down
            for (int i = rowbegin; i <= rowend; i++) {
                result.push_back(matrix[i][colend]);
            }
            colend--;

            // Traverse left
            if (rowbegin <= rowend) {
                for (int j = colend; j >= colbegin; j--) {
                    result.push_back(matrix[rowend][j]);
                }
                rowend--;
            }

            // Traverse up
            if (colbegin <= colend) {
                for (int i = rowend; i >= rowbegin; i--) {
                    result.push_back(matrix[i][colbegin]);
                }
                colbegin++;
            }
        }

        return result;
    }
};
