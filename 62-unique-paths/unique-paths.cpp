class Solution {
public:
    int r , c;
    int dfs(int i , int j,vector<vector<int>>& dp){
        if(i >= r || j >= c) return 0;

        if(i == r - 1 && j == c - 1){
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        
        int right = dfs(i,j+1,dp);
        int down =  dfs(i+1,j,dp);

        return dp[i][j] = (right + down);
    }
    int uniquePaths(int m, int n) {
        r = m;
        c = n;

        vector<vector<int>> dp(m,vector<int> (n,-1));

        return dfs(0,0,dp);
    }
};