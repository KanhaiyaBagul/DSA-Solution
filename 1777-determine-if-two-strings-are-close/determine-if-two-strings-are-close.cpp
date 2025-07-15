class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;

        vector<int> count1(26,0),count2 (26,0),ch1(26,0),ch2(26,0);
        for(int i = 0; i < word1.length(); i++){
            count1[word1[i] - 'a']++;
            ch1[word1[i] - 'a'] = 1;
            count2[word2[i] - 'a']++;
             ch2[word2[i] - 'a'] = 1;
            
        }
       
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        return (count1 == count2 && ch1 == ch2);
    

        
    }
};