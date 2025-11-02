class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> freqMagazine;

        for(char ch : magazine){
            freqMagazine[ch]++;
        }

        for(char ch : ransomNote){
            if(freqMagazine[ch] == 0){
                return false;
            }

            freqMagazine[ch]--;
        }
        return true;


        
    }
};