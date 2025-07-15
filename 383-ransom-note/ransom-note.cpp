class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freqMagazine(26,0);

        for(char ch : magazine){
            freqMagazine[ch - 'a']++;

        }

        for(char ch : ransomNote){
            if(freqMagazine[ch - 'a'] == 0){
                return false ;
            }

            freqMagazine[ch - 'a']--;
        }

        return true;
        
    }
};