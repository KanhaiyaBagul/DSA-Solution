class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue < pair < pair<int, int>, int >> q;//use queue here

        vector<vector<int>> vis(n,vector<int> (m));//we don't change the original grid we make changes here

            for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {//if we find the two the rotten oranges then push it to the queue
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        //moving in 4 direction
        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};
        int time = 0;

        while (!q.empty()) {
            int r = q.front().first.first;//the row of the element is present in the queue
            int c = q.front().first.second;//the colum 
            int t = q.front().second;
            q.pop();//pop the elemment

            time = max(time, t);//always select the max time

            for (int i = 0; i < 4; i++) {
                int nr = r + x[i];
                int nc = c + y[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    vis[nr][nc] != 2 && grid[nr][nc] == 1) {
                    vis[nr][nc] = 2;//if the new row and column are not "2" and the grid is "1" then make the vis "2"
                    q.push({{nr, nc}, time + 1});//push it to the queue with incrememnt of the time
                }
            }            
        }

        for(int i = 0; i < n; i++){
            for(int j = 0;j < m; j++){
                if(vis[i][j] != 2 && grid[i][j] ==1){//check if the grid is "1" but visited is not "2"
                    return -1;
                }
            }
        }


        return time;

    }
};