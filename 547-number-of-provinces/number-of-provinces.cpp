class Solution {
public:
    void dfs(int src , vector<vector<int>>& adj,vector<bool> &vis){
        vis[src] = true;

        for(int v : adj[src]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);

                }
            }
        }

        int count = 0;
        vector<bool> vis(V,false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;

            }
        }
        return count;
    }
};