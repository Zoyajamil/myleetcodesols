class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> res(1,1);
        long long prev=1;

        for(int i=1;i<=rowIndex;i++){
            long long ans=prev * (rowIndex-i+1)/i;
            res.push_back(ans);
            prev=ans;
        }

        return res;
    }
};
