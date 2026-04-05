class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(), piles.end()); 
        //[1 2 3 4 5 6 7 8 9 10 11]

        while(low<=high){
            int mid= low + (high-low) /2;
            long long total_hours=calculatehours(piles,mid);

            if(total_hours<=h){
                high=mid-1;
            } else{
                    low=mid+1;
                }
            }
            return low;
        }
    

    long long calculatehours(vector<int>& piles, int hourly){
        long long total_hours=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            total_hours+= (long long)ceil((double)piles[i]/(double)hourly);
        }
        return total_hours;
    }

};



/*class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            int total_hours = hours(piles, mid);

            if(total_hours <= h){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    int hours(vector<int>& piles, int mid){
        int total_hours = 0;

        for(int i = 0; i < piles.size(); i++){
            total_hours += (piles[i] + mid - 1) / mid;
        }
        return total_hours;
    }
};*/
