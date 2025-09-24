class Solution {
public:

    //use for cycle detection 
    bool helper(int src, vector<bool>& vis, vector<bool>& recPath,
                vector<vector<int>>& graph) {
        vis[src] = true;     // mark as visited
        recPath[src] = true; // mark for the cycle

        // go through ever neighbout node
        for (int v : graph[src]) {
            if (!vis[v]) { // if not visited
                if (helper(v, vis, recPath,
                           graph)) { // if it found the cycle return true
                    return true;
                }
            } else {
                // if already visited and present in the recPath that means it
                // is repeated and form the cycle
                if (recPath[v]) { // then return true
                    return true;
                }
            }
        }
        recPath[src] = false; // this is for backtrack
        return false;         // if no cycle is found then return false
    } 

    void topologicalSort(int src, vector<bool>& vis, stack<int>&s,vector<vector<int>>& graph){
        vis[src] = true;

        for(int v : graph[src]){
            if(!vis[v]){
                topologicalSort(v,vis,s,graph);
            }
        }

        s.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int v = numCourses;

        vector<bool> vis(v, false);     // tract for vis nodes
        vector<bool> resPath(v, false); // tract the current path

        vector<vector<int>> graph(numCourses); // this store the proper way of
                                               // nodes and the neighbours
        for (auto& p : prerequisites) {
            int u = p[1];
            int v = p[0];
            graph[u].push_back(v);
        }
        // this loop assure that every node is visited
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                // call for the helper and check if any cycle occure
                if (helper(i, vis, resPath, graph)) {
                    return {};// if the cycle found then return empyt means no topological sorting is able to perform
                }
            }
        }
        //for topological sort
        vector<int> result;
        stack<int> s;
        vector<bool> vis2(v,false); 

        for(int i = 0; i < v; i++){
            if(!vis2[i]){
                topologicalSort(i,vis2,s,graph);
            }
        }

        //put the stack in the result vector
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result;
        
    }
};