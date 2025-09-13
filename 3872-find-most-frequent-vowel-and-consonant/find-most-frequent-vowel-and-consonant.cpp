class Solution {
public:

    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch  == 'o' || ch == 'u');
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> vowels;
        unordered_map<char , int > consonant;

        //seperate vowels and the consonent in different hash map
        for(char ch : s){
            if(isVowel(ch)){
                vowels[ch]++;
            }else{
                consonant[ch]++;
            }
        }

        //here we initialize with zero for , if we don't have any pair it return 0
        int maxVowel = 0;
        int maxConsonent = 0;

        //fint the max freq
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