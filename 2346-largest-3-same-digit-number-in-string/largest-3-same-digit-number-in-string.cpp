class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string str = "";

        for(int i = 0; i < n - 2; i++){
            
            if(num[i] == num[i + 1] && num[i] == num[i + 2]){
                str = max(str, num.substr(i , 3));
            }
        }
        return str;
        
        
    }
};