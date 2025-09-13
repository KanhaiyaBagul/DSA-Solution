class Solution {
public:

    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch  == 'o' || ch == 'u');
    }
    int maxFreqSum(string s) {

        vector<int> alpha(26,0);
        //count the frequency of the alphabets
        for(char ch : s){
            alpha[ch - 'a']++;
        }

        int maxVowels = 0; 
        int maxConconent = 0;

        //fint the max freqency
        for(int i = 0; i < 26; i++){
            char ch = 'a' + i;
            if(isVowel(ch)){
                maxVowels = max(maxVowels, alpha[i]);
            }else{
                maxConconent = max(maxConconent , alpha[i]);
            }
        }

        //return the sum
        return maxVowels + maxConconent;

    
        
    }
};