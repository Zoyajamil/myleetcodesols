class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;
        int n=position.size();
        int high=position[n-1]-position[0];

        while(low<=high){
            int mid=(low+high) /2;
            if(canweplace(position,mid,m) == true){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }

    bool canweplace(vector<int>& position, int force, int m){
        int cntballs=1;
        int last=position[0];
        int n=position.size();

        for(int i=1; i<n;i++){
            if(position[i]-last >=force){
                cntballs++;
                last=position[i];
            }
            if(cntballs>=m) return true;
        }
        return false;
    }
};
