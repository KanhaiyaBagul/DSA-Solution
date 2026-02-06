class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i = 0; i < s.size() - 1; i++){
            int s1 = s[i] - 'a';
            int s2 = s[i+1] - 'a';
            score += abs(s1-s2);
        }
        return score;
        
    }
};