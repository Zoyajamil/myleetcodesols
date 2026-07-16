class Solution {
public:
    string reorganizeString(string s) {
       unordered_map<char,int> freq;

       for(char c : s){
            freq[c]++;
       }

       priority_queue<pair<int,char>> pq;

       for(auto &it : freq){
            pq.push({it.second, it.first});
       }

       pair<int,char> prev={0,'#'};
       string ans="";

       while(!pq.empty()){
            auto cur= pq.top();
            ans+=cur.second;
            pq.pop();
            cur.first--;
       

            if(prev.first > 0){
                pq.push(prev);
            }
       
            prev=cur;
        }

        if(ans.size() != s.size()){
            return "";
        }

    return ans;
    }
};
