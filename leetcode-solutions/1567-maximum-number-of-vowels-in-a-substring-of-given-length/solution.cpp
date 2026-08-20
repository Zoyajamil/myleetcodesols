class Solution {
public:
    bool isvowel(char c){
        return c =='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int maxvowel=0;
        int vowel=0;
        int start=0;


        for(int end=0 ; end<s.size() ; end++){
            if(isvowel(s[end])) {
                vowel++;
            }
            if(end-start+1 == k ){
                maxvowel= max(maxvowel, vowel);
            

            if(isvowel(s[start])){
                vowel--;
            }
            start++;
            }
        }
        return maxvowel;
    }   
};
