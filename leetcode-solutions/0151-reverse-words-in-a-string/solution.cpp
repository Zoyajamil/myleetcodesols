class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n=s.size();
        int i=0;
        int l=0;

        while(i<n){

            //skip spases
            while(i<n && s[i]==' ')
                i++;
            
            if(i>=n) break;

            int j=i; //mark start of word

            //find end of word
            while(j<n && s[j] !=' ')
                j++;

            //reverse the word
            reverse(s.begin() + i, s.begin() +j);

            //add single space if not first word
            if(l>0)
                s[l++]=' ';
            
            //copy word to the correct position
            for(int k=i;k<j;k++)
                s[l++]=s[k];

            i=j;
            
        }

        s.resize(l);
        return s;
    }
};



