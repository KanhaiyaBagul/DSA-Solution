class Solution {
public:
    int recursion(int n, vector<int>&dp){
        if(n == 0 || n  == 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += recursion(i,dp) * recursion(n-i-1,dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return recursion(n,dp);
        
    }
};