class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;

        int left=0;
        int maxcount=0;

        for(int right=0; right < s.size() ; right++){

            if(mpp.find(s[right]) != mpp.end()){
                left= max(left , mpp[s[right]] +1);
            } 
            mpp[s[right]] = right;
            maxcount= max(maxcount, right-left +1);
        }

        return maxcount;
        
    }
};
