class MinStack {
public:
    vector<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push_back(val);
    }
    
    void pop() {
        if(s.size()!=0){
            s.pop_back();
            return;
        }
        return;
        
    }
    
    int top() {
        if(s.size() != 0){
            return s[s.size()-1];
        }
        return -1;
        
    }
    
    int getMin() {

        int n = s.size();
        int minValue = INT_MAX;

        for(int i = 0; i < n ;i ++){
            minValue = min(minValue, s[i]);
        }
        return minValue;
        
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