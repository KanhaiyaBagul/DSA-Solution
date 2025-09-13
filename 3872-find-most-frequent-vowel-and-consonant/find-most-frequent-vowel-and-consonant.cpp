class Solution {
public:

    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch  == 'o' || ch == 'u');
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> vowels;
        unordered_map<char , int > consonant;

        for(char ch : s){
            if(isVowel(ch)){
                vowels[ch]++;
            }else{
                consonant[ch]++;
            }
        }

        int maxVowel = 0;
        int maxConsonent = 0;

        for(auto &pair : vowels){
            if(maxVowel < pair.second){
                maxVowel = pair.second;
            }
        }

        for(auto &pair : consonant){
            if(maxConsonent < pair.second){
                maxConsonent = pair.second;
            }
        }

        return maxVowel + maxConsonent;
        

        
        
    }
};