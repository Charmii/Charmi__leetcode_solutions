class MinStack {
    int min = INT_MAX;
    stack<int> st; 
    stack<int> min_stack;
public:
    MinStack() {
        // min_stack.push(min);
    }
    
    void push(int val) {
        if(min >= val){
            min = val;
            min_stack.push(min);
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top() == min_stack.top()) {
            min_stack.pop();
            if (!min_stack.empty()) {
                min = min_stack.top();
            } else {
                min = INT_MAX;
            }
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if(min_stack.empty()) return 0;
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */