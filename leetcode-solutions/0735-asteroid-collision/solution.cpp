class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int ast : asteroids){

            while(!st.empty() && ast<0 && st.back()>0){
                if(st.back() < -ast){
                    st.pop_back();
                    continue;
                }
                else if(st.back()== -ast){
                    st.pop_back();
                }

                goto next;
            }

            st.push_back(ast);

            next:;
        }
        return st;
    }
};
