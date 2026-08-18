class Solution {
public:
    vector<int> getRow(int rowindex) {
        std :: vector<int> res(1,1);
        long long prev=1;

        for(int i=1;i<=rowindex;i++){
            long long ans=prev * (rowindex-i+1) / i;
            res.push_back(ans);
            prev=ans;
        }
        return res;
    }
};
