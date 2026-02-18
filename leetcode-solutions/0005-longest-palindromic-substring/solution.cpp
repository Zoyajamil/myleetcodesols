class Solution {
public:

    int expand(string &s, int left,int right){
        while(left>=0 && right< s.size() && s[left]==s[right]){
            left--;
            right++;
        }

        return right-left-1;
    }


    string longestPalindrome(string s) {
        int n=s.size();

        if(n<2) return s;

        int start=0;
        int maxLen=1;

        for(int i=0;i<n;i++){
            int len1=expand(s,i,i); //Odd length center at i

            int len2=expand(s,i,i+1);

            int curMax=max(len1,len2);

            if(curMax > maxLen){
                maxLen=curMax;
                start= i-(curMax-1)/2; //compute new starting index 
            }
        }

        return s.substr(start,maxLen);
    }
};
