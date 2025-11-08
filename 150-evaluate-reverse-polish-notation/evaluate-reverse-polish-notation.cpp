class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;

        for(string ch : tokens){
            //if we find any operator then perform the operation and push it to the stack
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/"){
                int num2 = (s.top());
                s.pop();
                int  num1 = (s.top());
                s.pop();

                if(ch == "+") s.push(num1 + num2);
                else if(ch == "-") s.push(num1 - num2);
                else if(ch == "*") s.push(num1 * num2);
                else if(ch == "/") s.push(num1 / num2);
            }else{//if we don't find the operator then push the string as integer
                s.push(stoi(ch));
            }

        }
        return (s.top());
        
    }
};