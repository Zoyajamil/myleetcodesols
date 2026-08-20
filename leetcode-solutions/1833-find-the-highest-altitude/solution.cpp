class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx=0;

        for(int i=0; i<=gain.size(); i++){
            int alt=0;

            for(int j=0; j<i ; j++){
                alt+=gain[j];
            }
            mx=max(mx,alt);
        }
        return mx;
    }
};
