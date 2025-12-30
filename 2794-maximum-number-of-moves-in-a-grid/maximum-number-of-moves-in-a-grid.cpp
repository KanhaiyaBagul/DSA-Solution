class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    bool isValid(int i,int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int dfs(int r,int c,vector<vector<int>>& grid){

        if(dp[r][c] != -1) return dp[r][c];
        

        int x[] = {-1,0,1};
        int y[] = {1,1,1};

        int best = 0;

        for(int i = 0; i < 3; i++){
            int nr = r + x[i];
            int nc = c + y[i];

            if(isValid(nr,nc) && grid[r][c] < grid[nr][nc]){
                best = max(best,1 + dfs(nr,nc,grid));
            }
        }
        return dp[r][c] = best;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<int>(n,-1));

        int ans = 0;

        for(int i = 0; i < m; i++){
            ans = max(ans, dfs(i,0,grid));
        }
        return ans;   
    }
};