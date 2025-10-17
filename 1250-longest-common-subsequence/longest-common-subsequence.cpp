class Solution {
public:

    int LCSHelper(int i , int j,string &text1, string &text2,vector<vector<int>> &dp){
        //base case if our index get out of  bound it return form their
        if(i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + LCSHelper(i - 1, j -1 , text1, text2, dp);
        }else{
            int ans1 = LCSHelper(i - 1, j, text1, text2, dp);
            int ans2 =  LCSHelper(i, j -1 , text1, text2, dp);
            return dp[i][j] = max(ans1, ans2);
        }
    } 
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size() - 1;
        int j = text2.size() - 1;

        vector<vector<int>> dp(i + 1, vector<int> (j + 1, -1));
        return LCSHelper(i,j,text1,text2,dp);
        
    }
};