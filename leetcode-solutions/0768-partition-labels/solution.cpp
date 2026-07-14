class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last_occurence;
        for(int i=0; i < s.size(); i++){
            last_occurence[s[i]] = i;   //storing the last occurence of a char in a map
        }

        int start=0;
        int end=0;
        vector<int> result;

        for(int i=0; i<s.size() ; i++){
            end=max(end, last_occurence[s[i]]);
            if(i==end){
                result.push_back(end-start + 1);
                start= i+1;
        }
    }
    return result;
    }
};
