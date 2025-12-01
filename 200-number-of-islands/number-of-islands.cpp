class Solution {
public:
    int n , m;
    void dfs(int r, int c,vector<vector<char>>& grid){

        if(r >= m || r < 0 || c >= n || c < 0 || grid[r][c] == '0'){
            return;
        }

        grid[r][c] = '0';

        int x[4] = {-1,0,1,0};
        int y[4] = {0,1,0,-1};

        for(int i = 0; i < 4; i++){
            int nr = r + x[i];
            int nc = c + y[i];

            dfs(nr, nc,grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count ++;
                    dfs(i,j,grid);

                }
            }
        }
        return count;
        
    }
};