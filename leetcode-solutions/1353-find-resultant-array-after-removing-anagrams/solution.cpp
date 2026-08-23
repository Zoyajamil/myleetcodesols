class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;


        res.push_back(words[0]);

        for(int i=1;i<words.size();i++){
            string a= words[i];
            string b=res.back();

            string sortedA=a;
            string sortedB=b;

            sort(sortedA.begin() , sortedA.end());
            sort(sortedB.begin() , sortedB.end());

            if(sortedA != sortedB){
                res.push_back(words[i]);
            }
        }
        return res;

    }
};
