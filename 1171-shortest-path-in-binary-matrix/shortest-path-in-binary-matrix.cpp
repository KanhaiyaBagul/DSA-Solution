class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int sr = 0;
        int sc = 0;

        

        int n = grid.size();
        int m = grid[0].size();

        if (n == 1 && m == 1) return grid[0][0] == 0 ? 1 : -1;

// If start or end is blocked
if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;



        

        vector<vector<int>> dist(n, vector<int> (m , INT_MAX));
        dist[sr][sc] = 1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1,{sr,sc}});

        vector<int> dr = {-1,-1,0,1,1,1,0,-1};
        vector<int> dc = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dista = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0; i < 8; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 0 && dista + 1 < dist[newr][newc]){
                    dist[newr][newc] = dista + 1;
                    if(newr ==  n - 1 && newc ==  n - 1){
                        return dista + 1;
                    }
                    q.push({dista + 1,{newr,newc}});
                }
            }


        }
        return -1;
        
    }
};