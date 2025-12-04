class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string result = "";

        int w1 = word1.size();
        int w2 = word2.size();
        for(i; i < min(w1,w2); i ++){
                result += word1[i];
                result += word2[i];
        }

        if(w1 < w2){
            result = result + word2.substr(i);
        }else{
            result = result + word1.substr(i);

        }
        return result;
        
    }
};