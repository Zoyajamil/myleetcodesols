class Solution {
public:
    bool arevectorsequal(vector<int> &a, vector<int> &b){
        for(int i=0;i<26;i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }


    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(char c : p){
            freq1[c-'a']++;
        }
        int i=0;
        int j=0;

        while(j<s.size()){
            freq2[s[j] -'a']++;

            if(j-i+1 == p.size()){
                if(arevectorsequal(freq1,freq2)){
                    res.push_back(i);
                }
            }

            if(j-i+1 < p.size()) j++;
            else{
                freq2[s[i]-'a']--;
                i++;
                j++;
            }
        }

        return res;
    }
};
