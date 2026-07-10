class Solution {
public:
    int maxDistance(vector<int>& position, int m) {

        // Sort basket positions
        sort(position.begin(), position.end());

        // Minimum possible answer
        int low = 1;

        int n = position.size();

        // Maximum possible answer
        int high = position[n - 1] - position[0];

        // Binary search on the answer
        while (low <= high) {

            int mid = (low + high) / 2;

            // Can we keep at least 'mid' distance between every pair?
            if (canweplace(position, mid, m)) {

                // Yes -> try for a larger minimum distance
                low = mid + 1;

            } else {

                // No -> decrease the distance
                high = mid - 1;
            }
        }

        // high stores the largest valid distance
        return high;
    }

    bool canweplace(vector<int>& position, int force, int m) {

        // Place first ball in the first basket
        int cntballs = 1;

        // Position of last placed ball
        int last = position[0];

        int n = position.size();

        // Try placing remaining balls greedily
        for (int i = 1; i < n; i++) {

            // If current basket is at least 'force' away
            if (position[i] - last >= force) {

                // Place a ball here
                cntballs++;

                // Update last placed position
                last = position[i];
            }

            // Successfully placed all m balls
            if (cntballs >= m)
                return true;
        }

        // Couldn't place all balls
        return false;
    }
};

//search space is the minimum and the max distance possob;e between two baskets 
