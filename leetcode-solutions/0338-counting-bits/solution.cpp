class Solution {
public:
    vector<int> countBits(int n) {
        int cnt=0;
        vector<int> result(n+1);
        result[0]=0;

        if(n==0) return {0};

        for(int i=0; i<=n; i++){
            if(i%2==0){
                result[i]=result[i/2];
            }else{
                result[i]=result[i/2] +1;
            }
        }
        return result;
    }
};
