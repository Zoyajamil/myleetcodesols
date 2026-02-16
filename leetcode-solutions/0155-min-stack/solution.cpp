/*class MinStack {

private:
    stack<int> st;
    int mini;

public:
    MinStack() {
    }
    
    void push(int value) {
        
        //if stack is empty
        if(st.empty()){
            //update the minimum value
            mini=value;
            
            st.push(value);
            return;
    }

    if(value>mini){
        st.push(value);
    }else{
        //add modified value to the stack 
        st.push(2*value-mini);
        mini=value;
    }
    }

    //POP functino
    void pop(){
        if(st.empty()) return -1;

        int x=st.top();
        st.pop();

        if(x<mini){
            mini=2*mini-x; //update the minimim //previous element 
        }
    }

    int top(){
        if(st.empty()) return -1;
        int x=st.top();
        
        if(mini<x){
            return x;
        }else{
            return mini;
        }
    }

        int getMin(){
            if(st.empty()) return -1;
            return mini;
        }

};*/






/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class MinStack {
private:
    // Initialize a stack
    stack<long long> st;

    // To store the minimum value 
    long long mini;

public:
    
    // Empty Constructor
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        
        // If stack is empty
        if (st.empty()) {
            // Update the minimum value
            mini = value;
            
            // Push current value as minimum
            st.push(value);
            return;
        }
        
        // If the value is greater than the minimum
        if (value > mini) {
            st.push(value);
        }
        else {
            // Add the modified value to stack
            st.push(2LL * value - mini);
            
            // Update the minimum
            mini = value;
        }
    }
    
    // Method to pop a value from stack
    void pop() {
        
        // Base case
        if (st.empty()) return;
        
        // Get the top
        long long x = st.top();
        st.pop(); // Pop operation
        
        // If the modified value was added to stack
        if (x < mini) {
            // Update the minimum
            mini = 2LL * mini - x;
        }
    }
    
    // Method to get the top of stack
    int top() {
        
        // Base case
        if (st.empty()) return -1;
        
        // Get the top
        long long x = st.top();
        
        // Return top if minimum is less than the top
        if (x > mini) return x;
        
        // Otherwise return mini
        return mini;
    }
    
    // Method to get the minimum in stack
    int getMin() {
        
        // Base case
        if (st.empty()) return -1;
        
        // Return the minimum
        return mini;
    }
};


