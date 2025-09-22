class Solution {
public:

    bool dfs(int src, int dest, vector<vector<int>>&graph, vector<bool> &visited){
        if(src == dest){//if we find the destination
            return true;
        }
        visited[src] = true;//mark as visited
        for(int v : graph[src]){
            if(!visited[v]){//if it is not visited
                if(dfs(v, dest, graph, visited)){//if it gives true it return true throught the program 
                    return true;
                }
            }

        }
        return false;

    }

    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> graph(n);

        //first build the graph 
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n,false);
        return dfs(source, destination , graph, visited);
    }
};