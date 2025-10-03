class Solution {
public:
    void dfs(int src , vector<vector<int>>& isConnected,vector<bool> &vis){
        vis[src] = true;

        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[src][j] == 1 && !vis[j]){
                dfs(j,isConnected,vis);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
    
        int count = 0;
        vector<bool> vis(V,false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                count++;

            }
        }
        return count;
    }
};