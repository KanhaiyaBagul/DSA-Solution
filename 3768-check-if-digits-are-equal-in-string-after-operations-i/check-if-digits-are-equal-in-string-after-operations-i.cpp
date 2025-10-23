class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();

        while(s.size() > 2){
            string  temp = "";
            for(int i = 1; i < s.size();i++){
                int a = (s[i-1]) - '0';
                int b = (s[i]) - '0';

                int result = (a + b) % 10;
                temp += to_string(result);
            }
            s = temp;
        }

        return s[0] == s[1];
        
    }
};