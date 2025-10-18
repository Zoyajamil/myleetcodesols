/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        while (right < n) {
            if (mpp[s[right]] != -1)
                left = max(mpp[s[right]] + 1, left);

            mpp[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};*/


/*class solution{
public:
    int lengthofLongestsubstring(string s){
        vector<int> mpp(256,-1);
        int left=0,rigth=0;
        int n=s.size();
        int len=0;
        while (rigth < n){
            if(mpp[s[rigth]]!=-1)
                left= max(mpp[s[right]]+1,left);  //variable overloaded 
                //to move the left sliding pointer directly to the repeating characters index(one place next to the index)
            
            mpp[s[right]]=right; //update the map index of the variable

            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1); // map for last index of each character
        int left = 0, right = 0;
        int n = s.size();
        int len = 0;

        while (right < n) {
            if (mpp[s[right]] != -1)
                left = max(mpp[s[right]] + 1, left); // move left to avoid repeat

            mpp[s[right]] = right; // update character’s latest index
            len = max(len, right - left + 1);
            right++;
        }

        return len;
    }
};

