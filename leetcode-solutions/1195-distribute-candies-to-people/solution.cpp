class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);

        for(auto i=0; candies>0 ; i++){
            int give=min(candies, i+1);
            res[i%num_people] += give;
            candies-=give;
        }
        return res;
    }
};
