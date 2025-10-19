class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        //if both string are empty 
        dp[0][0] = true;

        for(int j = 1; j < m + 1; j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
            }else{//if it have ? and any other character then it is false
                dp[0][j] = false;
            }
        }

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){// if the character match then it depents on the previous one to decide , and if it is the ? then also matched
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }else{
                    //if the character are not same , then it is not possible
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
        
    }
};