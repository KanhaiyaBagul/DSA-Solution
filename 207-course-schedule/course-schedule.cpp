class Solution {
public:
    bool dfs(int u,vector<vector<int>>& grid,vector<bool>& vis,vector<bool>& path){
        
        vis[u] = true;

        path[u] = true;

        for(auto v : grid[u]){
            if(!vis[v]){
                if(dfs(v,grid,vis,path)){
                    return true;
                }
            }else if(path[v]){
                return true;
            }
        }

        path[u] = false;
        return false;



    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<bool> vis(v,false);
        vector<bool> path(v,false);

        vector<vector<int>> grid(v);

        for(auto& pair : prerequisites){
            int u = pair[0];
            int v = pair[1];

            grid[u].push_back(v);
        }

        for(int i = 0; i < v; i++){
            if(!vis[i]){
                if(dfs(i,grid,vis,path)){
                    return false;
                }
            }
        }
        return true;
    }
};