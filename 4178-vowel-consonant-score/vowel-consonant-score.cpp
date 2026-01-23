class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o';
    }
    int vowelConsonantScore(string s) {

        int vowels = 0;
        int consonent = 0;

        for(char ch : s){
            if(isVowel(ch)){
                vowels++;
            }else if(isdigit(ch) || ch == ' '){
                continue;
            }else{
                consonent++;
            }
        }

        return consonent == 0 ? 0 : vowels / consonent;
        
    }
};