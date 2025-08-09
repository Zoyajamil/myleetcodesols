class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();

        // Step 1: Find the break point
        int ind = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                ind = i;
                break;
            }
        }

        // If no break point, reverse the whole array
        if (ind == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 2: Swap with next greater element
        for (int i = n - 1; i > ind; i--) {
            if (A[i] > A[ind]) {
                swap(A[i], A[ind]);
                break;
            }
        }

        // Step 3: Reverse the right half
        reverse(A.begin() + ind + 1, A.end());
    }
};

