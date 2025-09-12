class Solution {
public:

    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    bool doesAliceWin(string s) {
        if(s.empty()) return true;
        int count = 0;
        for(char ch : s){
            if(isVowel(ch)){
                return true;
            }
        }


       
       return false; 
        

        
    }
};