class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> all;
        string str;
        int i=0;
        dfs(s,i,str,all);
        return all;
    }
private:
    void dfs(string& s,int i,string str, vector<string>& all){
        if(i==s.size()) all.push_back(str);
        else{
            if(s[i]>='0' && s[i]<='9'){
            str.push_back(s[i]);
            dfs(s,i+1,str,all); 
            str.pop_back();           
        }
        else{
            str.push_back(tolower(s[i]));
            dfs(s,i+1,str,all);
            str.pop_back();

            str.push_back(toupper(s[i]));
            dfs(s,i+1,str,all);
            str.pop_back();

        }
        }
    }
};
