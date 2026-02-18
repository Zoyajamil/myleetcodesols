class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string first= strs.front();
        string last= strs.back();

        string ans = "";

        int minLength = min(first.size(), last.size());

        for(int i=0; i< minLength;i++){
            if(first[i]!=last[i]) break;
            ans +=first[i];
        }

        return ans;
    }
};
