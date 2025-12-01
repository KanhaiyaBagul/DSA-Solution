class Solution {
public:
    int m, n;
    int helper(int r, int c,vector<vector<int>>& grid){
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0){
            return 0;
        }

        grid[r][c] = 0;

        int x[] = {-1,0,1,0};
        int y[] = {0,1,0,-1};
        
        int currAns = 1;

        for(int i = 0; i < 4; i++){
            currAns += helper(r + x[i] , c + y[i],grid);
        }
        return currAns;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea,helper(i,j,grid));
                }
            }
        }
        return maxArea;

        
    }
};