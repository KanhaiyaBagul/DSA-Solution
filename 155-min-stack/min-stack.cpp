class MinStack {
public:
    vector<int> s;
    vector<int> minValue;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push_back(val);

        //if we find the min val then add to the minvector
        if(minValue.empty() || val <= minValue.back()){
            minValue.push_back(val);
        }
    }
    
    void pop() {
        if(s.size()!=0){
            if(s.back() == minValue.back()){//if the poping element is the min then also pop from the minValue vector
                minValue.pop_back();
            }
            s.pop_back();
        }
        return;
        
    }
    
    int top() {
        if(s.size() != 0){
            return s.back();
        }
        return -1;
        
    }
    
    int getMin() {
        return minValue.empty()? -1 : minValue.back();//if the minValue is not empyt then return the mingValue;
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