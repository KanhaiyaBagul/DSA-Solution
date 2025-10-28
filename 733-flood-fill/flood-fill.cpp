class Solution {
public:
    void dfs(int r, int c, int n, int m ,vector<vector<int>>& image,vector<vector<bool>>& vis,int oldColor, int newColor){

        image[r][c] = newColor;
        vis[r][c] = true;

        vector<int> x = {-1,1,0,0};
        vector<int> y = {0,0,1,-1};

        for(int i = 0; i < x.size(); i ++){
            int nr = r + x[i];
            int nc = c + y[i];

            if(nr < n && nc < m && nr >= 0 && nc >= 0 && image[nr][nc] == oldColor && !vis[nr][nc]){
                dfs(nr,nc,n,m,image,vis,oldColor,newColor);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> vis(n,vector<bool> (m,false));

        dfs(sr,sc,n,m,image,vis,image[sr][sc],color);

        return image;

        
    }
};