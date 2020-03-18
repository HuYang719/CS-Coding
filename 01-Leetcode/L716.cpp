class MaxStack {
public:
    /** initialize your data structure here. */
    stack<int> regular_stack;
    stack<int> max_stack; // only remember the largest
    MaxStack() {}
    
    void push(int x) {
        regular_stack.push(x);
        if(max_stack.empty())
            max_stack.push(x);
        else{
            if(x > max_stack.top())
                max_stack.push(x);
            else max_stack.push(max_stack.top());
        }
        
    }
    
    int pop() {
        int x = regular_stack.top();
        regular_stack.pop();
        max_stack.pop();
        return x;
        
    }
    
    int top() {
        return regular_stack.top();
        
    }
    
    int peekMax() {
        
        return max_stack.top();
        
    }
    
    int popMax() {
        int x = max_stack.top();
        stack<int> tmp;
        while(top() != x){
            tmp.push(regular_stack.top());
            regular_stack.pop();
            max_stack.pop();
        }
        regular_stack.pop();
        max_stack.pop();
        while(!tmp.empty()){
            push(tmp.top());
            tmp.pop();
        }
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */