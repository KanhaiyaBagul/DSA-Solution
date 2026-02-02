class Solution {
public:
    string reverseByType(string s) {
        string lower = "";
        string special = "";

        for(char &ch : s){
            if(islower(ch)){
                lower.push_back(ch);
            }else{
                
                special.push_back(ch);
            }
        }

        reverse(lower.begin(),lower.end());
        reverse(special.begin(),special.end());

        string result = "";
        int i = 0; 
        int j = 0;
        for(char &ch : s){
            if(islower(ch)){
                result += lower[i++];
            }else{
                result += special[j++];
            }
        }
        return result;
        
    }
};