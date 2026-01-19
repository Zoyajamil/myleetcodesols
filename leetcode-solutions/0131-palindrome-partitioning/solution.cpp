class Solution {
public:

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;

        backtrack(0, s, current, result);
        return result;
    }


    // Backtracking function
    void backtrack(int index, string &s,
                   vector<string> &current,
                   vector<vector<string>> &result) {

        // If we've used the entire string
        if (index == s.size()) {
            result.push_back(current);
            return;
        }

        // Try all possible partitions starting at index
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                current.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, s, current, result);
                current.pop_back(); // backtrack
            }
        }
    }


    // Check if s[l..r] is a palindrome
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};

