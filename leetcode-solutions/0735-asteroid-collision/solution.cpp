class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        // Use vector as a stack to store surviving asteroids
        vector<int> st;

        // Process each asteroid one by one
        for (int ast : asteroids) {

            // Collision occurs only when:
            // Stack top is moving right (+ve) and current asteroid is moving left (-ve)
            while (!st.empty() && ast < 0 && st.back() > 0) {

                // Current asteroid is larger, so destroy the stack top
                if (st.back() < -ast) {
                    st.pop_back();
                    continue;   // Check for more collisions
                }

                // Both asteroids are of equal size, so both explode
                else if (st.back() == -ast) {
                    st.pop_back();
                }

                // Current asteroid is destroyed (or both destroyed),
                // so skip pushing it into the stack
                goto next;
            }

            // No collision, so current asteroid survives
            st.push_back(ast);

            next:;
        }

        // Remaining asteroids in the stack are the answer
        return st;
    }
};
