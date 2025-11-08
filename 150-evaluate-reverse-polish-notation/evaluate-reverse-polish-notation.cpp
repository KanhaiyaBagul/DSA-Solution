class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;

        for(string ch : tokens){
            //if we find any operator then perform the operation and push it to the stack
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/"){
                int a = (s.top());
                s.pop();
                int  b = (s.top());
                s.pop();

                int result = 0;
                if(ch == "+"){
                    result = a + b;
                    s.push(result);
                }if(ch == "-"){
                    result = b - a;
                    s.push((result));
                    
                }if(ch == "*"){
                    result = a * b;
                    s.push((result));
                }if(ch == "/"){
                    if(a != 0){
                        result = b / a;
                    s.push((result));
                    }
                    
                }
            }else{//if we don't find the operator then push the string as integer
                s.push(stoi(ch));
            }

        }
        return (s.top());
        
    }
};