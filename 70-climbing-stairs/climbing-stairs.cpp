class Solution {
public:

    int helperr(int n , vector<int>& dp){
        if(n == 0 || n == 1){//if n == 0 means only have one way and if n == 1 then it also have one way
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = helperr(n-1,dp) + helperr(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1,-1);
        
        return helperr(n,dp);

        
        
    }
};