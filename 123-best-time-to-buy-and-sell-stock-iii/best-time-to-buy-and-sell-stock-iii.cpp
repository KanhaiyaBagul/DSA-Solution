class Solution {
public:

    int recursion(vector<int>& prices, int i ,int n, int k,vector<vector<int>>& dp){
        
        if(i == n || k == 0){
            return 0;
        }

        if(dp[i][k] != -1){
            return dp[i][k];
        }

        //Buy
        if(k == 4 || k == 2){
            int buy = recursion(prices,i+1,n,k-1,dp) - prices[i];
            int skip = recursion(prices,i+1,n,k,dp);

            return dp[i][k] =  max(buy,skip);
        }
        //Sell
        else{
            int sell = recursion(prices,i+1,n,k-1,dp) + prices[i];
            int skip = recursion(prices,i+1,n,k,dp);
            return dp[i][k] =  max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 4;

        vector<vector<int>> dp(n,vector<int>(5,-1));

        int gain = recursion(prices,0,n,k,dp);
        return gain;
        
    }
};