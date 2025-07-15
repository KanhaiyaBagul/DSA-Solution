class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> s1count(26,0);
        vector<int> s2count(26,0);
        int left = 0;

        for(int i = 0; i < s1.size(); i++){
            s1count[s1[i] - 'a'] ++;
            s2count[s2[i] - 'a'] ++;

        }

        if(s1count == s2count) return true;

        for(int i = s1.size(); i < s2.size(); i ++){

            s2count[s2[left] - 'a']--;
            s2count[s2[i] - 'a']++;
            if(s1count == s2count) return true;
            left++;

        }
        

        return false;
        
    }
};