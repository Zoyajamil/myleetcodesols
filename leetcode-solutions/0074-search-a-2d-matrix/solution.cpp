class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();       // Number of rows in the matrix
        int m = matrix[0].size();    // Number of columns in the matrix
        
        // We will treat the matrix like a single sorted 1D array
        // low = starting index, high = ending index in this 1D view
        int low = 0, high = n * m - 1;

        // Standard binary search
        while (low <= high) {
            int mid = (low + high) / 2; // Middle index in the "virtual" 1D array
            
            // Convert the 1D mid index into 2D coordinates (row, col)
            int row = mid / m; // Integer division gives the row number
            int col = mid % m; // Remainder gives the column number
            
            // If the middle element matches the target, return true
            if (matrix[row][col] == target) 
                return true;
            // If the middle element is less than target, search right half
            else if (matrix[row][col] < target) 
                low = mid + 1;
            // If the middle element is greater than target, search left half
            else 
                high = mid - 1;
        }
        
        // Target not found
        return false;
    }
};

