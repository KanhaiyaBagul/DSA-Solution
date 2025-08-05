class Solution {
public:
    bool isValid(string s) {

        stack<char> c;

        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{'){
                c.push(ch);
            }else{
                if(c.empty()){
                    return false;
                }

                int top = c.top();
                if((top == '{' && ch =='}') || (top == '[' && ch ==']') || (top == '(' && ch ==')')){
                    c.pop();


                }else{
                    return false;
                }



            }
        }

        if(c.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};