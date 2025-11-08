class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<string> s;

        for(string ch : tokens){
            if(ch != "+" && ch != "-" && ch != "*" && ch != "/"){
                s.push(ch);
            }else{
                int a = stoi(s.top());
                s.pop();
                int  b = stoi(s.top());
                s.pop();

                int result = 0;
                if(ch == "+"){
                    result = a + b;
                    s.push(to_string(result));
                }if(ch == "-"){
                    result = b - a;
                    s.push(to_string(result));
                    
                }if(ch == "*"){
                    result = a * b;
                    s.push(to_string(result));
                }if(ch == "/"){
                    if(a != 0){
                        result = b / a;
                    s.push(to_string(result));
                    }
                    
                }



            }

        }
        return stoi(s.top());
        
    }
};