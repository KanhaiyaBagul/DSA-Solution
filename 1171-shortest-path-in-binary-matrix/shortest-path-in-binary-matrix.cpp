class Solution {
public:
    int m,n;

    bool isSafe(int r, int c){
        return r >=0 && c >= 0 && r < m && c < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(grid[0][0] == 1 || grid[m-1][n-1]) return -1;

        using P = pair<int, pair<int,int>>;

        vector<vector<int>> dist(m,vector<int> (n,INT_MAX));
        dist[0][0] = 0;

        priority_queue<P,vector<P>, greater<P>> pq;

        pq.push({0,{0,0}});

        int x[] = {-1,-1,0,1,1,1,0,-1};
        int y[] = {0,1,1,1,0,-1,-1,-1};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            for(int i = 0; i < 8; i++){
                int nr = r + x[i];
                int nc = c + y[i];

                if(isSafe(nr,nc) && grid[nr][nc] == 0){
                    if(dist[nr][nc] > d + 1){
                        dist[nr][nc] = d + 1;
                        pq.push({d+1,{nr,nc}});
                    }
                }
            }

        }
        return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1] + 1;
        
    }
};