class Solution {
public:

    bool dfs(int src, int dest, vector<vector<int>>&graph, vector<bool> &visited){
        if(src == dest){
            return true;
        }
        visited[src] = true;
        vector<int> neighbour = graph[src];
        for(int v : neighbour){
            if(!visited[v]){
                if(dfs(v, dest, graph, visited)){
                    return true;
                }
            }

        }
        return false;

    }

    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> graph(n);

        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n,false);
        return dfs(source, destination , graph, visited);
    }
};