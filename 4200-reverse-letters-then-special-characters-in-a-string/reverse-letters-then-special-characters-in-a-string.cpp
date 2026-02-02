class Solution {
public:
    string reverseByType(string s) {
        string lower = "";
        string special = "";

        for(char ch : s){
            if(islower(ch)){
                lower = ch + lower;
            }else{
                special = ch + special;
            }
        }

        string result = "";
        int i = 0; 
        int j = 0;
        for(char ch : s){
            if(islower(ch)){
                result += lower[i++];
            }else{
                result += special[j++];
            }
        }
        return result;
        
    }
};