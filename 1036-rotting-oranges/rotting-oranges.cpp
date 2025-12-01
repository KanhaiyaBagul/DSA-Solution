class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        

        queue < pair < pair<int, int>, int >> q;

        vector<vector<int>> vis(n,vector<int> (m));

            for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};
        int time = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nr = r + x[i];
                int nc = c + y[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    vis[nr][nc] != 2 && grid[nr][nc] == 1) {
                    vis[nr][nc] = 2;
                    q.push({{nr, nc}, time + 1});
                }
            }            
        }

        for(int i = 0; i < n; i++){
            for(int j = 0;j < m; j++){
                if(vis[i][j] != 2 && grid[i][j] ==1){
                    return -1;
                }
            }
        }


        return time;

    }
};