class Solution {
public:
    //we use BFS 
    //increase level for each level;
    int m, n;
    bool isSafe(int r, int c){
        return r >=0 && c >= 0 && r < m && c < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if (m == 0 || n == 0 || grid[0][0] != 0) return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});//initial condition

        //moving in 8 direction
        int x[] = {-1,-1,0,1,1,1,0,-1};
        int y[] = {0,1,1,1,0,-1,-1,-1};
        int level = 0;

        while (!q.empty()) {

            int size = q.size();//initial size of the queue

            for (int i = 0; i < size; i++) {
                auto curr = q.front();//get the firstt element
                q.pop();//pop it

                int r = curr.first;
                int c = curr.second;

                if(r == m - 1 && c == n - 1){
                    return level + 1;//if the r and c reach the last index return the level
                }

                for (int k = 0; k < 8; k++) {

                    int nr = r + x[k];
                    int nc = c + y[k];

                    if(isSafe(nr,nc) && grid[nr][nc] == 0){
                        q.push({nr,nc});
                        grid[nr][nc] = 1;

                    }

                }
            }

            level++;
        }
        return -1;
    }
};