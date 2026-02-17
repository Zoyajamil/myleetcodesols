/*class StockSpanner {

private:
    //function to find the indices of previous greater element 
    vector<int> findPGE(vector<int> arr){
        int n=arr.size();

        vector<int> ans(n); //to store pge

        stack<int> st; //stack to get elements in LIFO form

        for(int i=0;i<n;i++){
            int currEle = arr[i];

            //pop elements until no element left or st top is greater than curr element 
            while(!st.empty() && arr[st.top()]<=currEle){
                st.pop();
            }

            if(st.empty())
                ans[i]=-1;

            else
                ans[i]=st.top();

            st.push(i);

        }
        return ans;
    }

public:
    vector<int> StockSpanner(vector<int> arr, int n) {
        vector<int> PGE=findPGE(arr);
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i]= i-PGE[i];
        }

        return ans;
    }
    
};*/

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


/*class StockSpanner {
private:
    
    // Stack to store pair of {price, span}
    stack<pair<int,int>> st;

public:
    
    // Constructor
    StockSpanner() {
        
    }
    
    // Function to return the span of current stock price
    int next(int price) {
        
        // Initially span is 1 (today itself)
        int span = 1;
        
        /* Pop elements from stack while stack is not empty
        and top price is less than or equal to current price 
        while(!st.empty() && st.top().first <= price) {
            
            // Add the span of popped element
            span += st.top().second;
            
            st.pop();
        }
        
        // Push current price and its span
        st.push({price, span});
        
        // Return the span
        return span;
    }
};
*/


class StockSpanner {

private:
    // Vector to store all stock prices
    vector<int> arr;

    // Stack to store indices of previous greater elements
    stack<int> st;

public:
    
    // Constructor
    StockSpanner() {
        
    }
    
    // Function to return the span of current stock price
    int next(int price) {
        
        // Add current price to array
        arr.push_back(price);
        
        // Current index
        int i = arr.size() - 1;
        
        /* Pop elements from stack until stack is not empty
        and top element is greater than current price */
        while(!st.empty() && arr[st.top()] <= price) {
            st.pop();
        }
        
        int span;
        
        /* If no previous greater element found,
        span is entire length till now */
        if(st.empty())
            span = i + 1;
        else
            span = i - st.top();
        
        // Push current index into stack
        st.push(i);
        
        // Return the span
        return span;
    }
};

