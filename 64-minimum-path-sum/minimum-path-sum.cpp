class Solution {
public:
    int m,n;
    
    int dfs(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& dp){

        if(i >= m || j >= n) return INT_MAX;//if it get out of bound then return the max Value

    
        if(i == m - 1 && j == n - 1){
            return grid[i][j];//if we reach the destination
        }

        if(dp[i][j] != -1) return dp[i][j];

    
        int down = dfs(i + 1,j,grid,dp);
        int up = dfs(i,j + 1,grid,dp);
        return dp[i][j] = grid[i][j]  + min(down,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return dfs(0,0,grid,dp);

        
        
    }
};