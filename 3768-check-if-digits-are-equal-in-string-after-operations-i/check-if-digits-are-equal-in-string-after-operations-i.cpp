class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        //run loop while the size is greater than 2
        while(s.size() > 2){
            string  temp = "";
            for(int i = 1; i < s.size();i++){
                int a = (s[i-1]) - '0';//first element
                int b = (s[i]) - '0';//second element

                int result = (a + b) % 10;//get the modulo
                temp += to_string(result);//add it to result
            }
            s = temp;//update the s
        }

        return s[0] == s[1];//check if they are equal or not 
        
    }
};