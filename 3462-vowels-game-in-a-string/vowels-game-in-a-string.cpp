class Solution {
public:

    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    //If the string has 0 vowels → Alice loses (false).
    //If the string has ≥1 vowel → Alice wins (true)


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