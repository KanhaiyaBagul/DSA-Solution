class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

//         If dp[i][j - coins[i-1]] == INT_MAX,
//         then adding 1 causes overflow, giving a negative number.
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1,1e9));

        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 0;
        }

        for(int i = 1; i < n + 1; i ++){
            for(int j = 1; j < amount + 1; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]],dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }

        }
        return dp[n][amount] == 1e9 ? -1: dp[n][amount];
        
    }
};