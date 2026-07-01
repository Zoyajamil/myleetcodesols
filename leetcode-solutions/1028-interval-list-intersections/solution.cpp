class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B ) {
        vector<vector<int>> result;
        int aptr=0;
        int bptr=0;
        vector<int> temp(2);
        int a=A.size();
        int b=B.size();

        while(aptr<a && bptr<b){
            if(B[bptr][0]<=A[aptr][1] && A[aptr][0]<=B[bptr][1] ){
                temp[0]=max(A[aptr][0], B[bptr][0]);
                temp[1]=min(B[bptr][1], A[aptr][1]);
                result.push_back(temp);
            }

            if(A[aptr][1] > B[bptr][1]){
                bptr++;
            }else{
                aptr++;
            }

            if(aptr>a || bptr>b){
                break;
            }
        }

    return result;
    }
};
