class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if(n < 3){
            return s;
        }

        string result;
        result.push_back(s[0]);
        for(int i = 1; i < s.size() - 1; i ++){
            if(s[i] == s[i + 1] && s[i] == s[i - 1]){
                result = result;

            }else{
                result.push_back(s[i]);
            }
            
        }
        result.push_back(s[n - 1]);


        return result;
        
    }
};