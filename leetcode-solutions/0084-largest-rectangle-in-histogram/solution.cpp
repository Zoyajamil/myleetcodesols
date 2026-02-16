class Solution {
public:
    int largestRectangleArea(vector<int> &histo) {
        stack<int> st;
        int maxA=0;
        int n=histo.size();

        //loop through each bar 
        for(int i=0;i<=n;i++){
            //while current bar is smaller then the stack top or end reached 
            while(!st.empty() && (i==n || histo[i]<=histo[st.top()])){
                
                int height= histo[st.top()]; //height of the bar at the top of the stack  
                st.pop(); //remove that bar

                int width;
                if(st.empty()){
                    width=i; //all bars previous were highrer 
                }else{
                    width=i-st.top() -1; //width between current index and index at the top
                    //i=nse-pse-1
                }

                //calc area and upadate the max area 
                maxA=max(maxA, width*height);

            }
            //push current index into stack 
            st.push(i);
        }
        return maxA;
        
    }
};
