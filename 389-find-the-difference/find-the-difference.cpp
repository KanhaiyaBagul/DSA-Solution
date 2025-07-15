class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0;
        int sum2 = 0;
        int n =  max(s.size(),t.size());
        for(int i = 0; i < n; i++){
            sum1 += (s.size() > i) ? s[i] : 0; 
            sum2 += t[i];
            
        }

        

        return char(sum2-sum1);
        
    }
};