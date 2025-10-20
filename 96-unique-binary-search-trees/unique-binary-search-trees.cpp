class Solution {
public:
    //for the catlan number 
        //c0 = 1;
        //c1 = 1;
        //c2 = c0*c1 + c1*c0
        //c3 = c2*c0 + c1*c1 + c0*c2
        //cn = 0 -----> n-1
        //          *
        //      n-1 -----> 0
    int recursion(int n, vector<int>&dp){
        if(n == 0 || n  == 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = 0;
        //it is the problme of catalans 
        //we have to calculate like 
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