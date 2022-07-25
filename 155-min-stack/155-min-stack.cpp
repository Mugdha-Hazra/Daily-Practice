class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty())
            stk.emplace(val,val);
        else
            stk.emplace(val,min(val,stk.top().second));        
    }
    
    void pop() {
        stk.pop();        
    }
    
    int top() {
        return stk.top().first;
        
    }
    
    int getMin() {
        return stk.top().second;
        
    }
    private:
    stack<pair<int,int>> stk; //stk.first is my value & stk.second contains the minimum 
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */