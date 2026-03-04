class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        
        // Step 1: Store first and last occurrence
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        
        vector<pair<int,int>> intervals;
        
        // Step 2: Try forming valid interval from each character's first occurrence
        for (int i = 0; i < n; i++) {
            if (i != first[s[i] - 'a']) continue;  // only start at first occurrence
            
            int start = i;
            int end = last[s[i] - 'a'];
            bool valid = true;
            
            // Expand interval
            for (int j = start; j <= end; j++) {
                if (first[s[j] - 'a'] < start) {
                    valid = false;
                    break;
                }
                end = max(end, last[s[j] - 'a']);
            }
            
            if (valid)
                intervals.push_back({start, end});
        }
        
        // Step 3: Sort by end index (Greedy selection)
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });
        
        vector<string> result;
        int prevEnd = -1;
        
        // Step 4: Select non-overlapping intervals
        for (auto &it : intervals) {
            if (it.first > prevEnd) {
                result.push_back(s.substr(it.first, it.second - it.first + 1));
                prevEnd = it.second;
            }
        }
        
        return result;
    }
};
