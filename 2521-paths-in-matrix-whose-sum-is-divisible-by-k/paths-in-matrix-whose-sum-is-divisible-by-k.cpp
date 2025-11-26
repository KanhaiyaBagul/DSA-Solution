class Solution {
public:
    int m , n;
    const long long MOD = 1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(int r, int c, vector<vector<int>>& grid , int sum,int k){
        if(r >= m  || c >= n){
            return 0;
        }

        if(r == m - 1 && c == n - 1){
            return (sum + grid[r][c]) % k == 0;
        }

        if(dp[r][c][sum] != -1){
            return dp[r][c][sum];
        }

        int down = solve(r + 1,c,grid,(sum + grid[r][c]) % k , k);
        int right = solve(r,c + 1,grid,(sum + grid[r][c]) % k , k);

        return dp[r][c][sum] = (down + right) % MOD;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int> (k,-1)));

        return solve(0,0,grid,0,k);
    }
};