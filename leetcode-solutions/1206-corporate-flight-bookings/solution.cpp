class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2,0);

        for(auto &b : bookings){
            int start=b[0];
            int end=b[1];
            int seats=b[2];

            diff[start]+= seats;
            diff[end+1]-= seats;

        }
        
        vector<int> result;
        int ans=0;

        for(int i=1;i<=n;i++){
            //cumulative sum
            ans+=diff[i];
            result.push_back(ans);
        }
        
        return result;
    }
};

//DIFFERENCE ARRAY TECHNIQUE //if not getting watch- codestorywith MIK
