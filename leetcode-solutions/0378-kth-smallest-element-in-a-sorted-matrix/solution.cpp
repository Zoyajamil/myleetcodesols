class Solution { // 20 ms, faster than 98.92%
public:
    int m, n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square

        int left = matrix[0][0];
        int right = matrix[m-1][n-1];
        int ans = -1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid) >= k) {   ///if the no of elements less than thr mid is greater than or equal to k
                ans = mid;
                right = mid - 1; // try to looking for a smaller value in the left side
            } else left = mid + 1; // try to looking for a bigger value in the right side
        }
        return ans;
    }


    int countLessOrEqual(vector<vector<int>>& matrix, int x) {  //to count the no of elements less than mid, if its equal to k, 
                                                                //and exists in matrix then it is our answer 

        int cnt = 0, c = n - 1; // start with the rightmost column
        for (int r = 0; r < m; ++r) {
            
            while (c >= 0 && matrix[r][c] > x)
                 --c;  // decrease column until matrix[r][c] <= x
            cnt += (c + 1);
        }
        return cnt;
    }
};
