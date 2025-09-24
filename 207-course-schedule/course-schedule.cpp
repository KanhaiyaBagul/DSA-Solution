    //in this question we have to return that if we can take the course 
    //We can attend ,if we do the 2nd course before 1 
    //we have to apply topological sort here , for that we require the Directed Acyclic graph 
    //if the cycle occure then it fail to attend the courses 
    //so here we just have to find it is directed and acyclic 
    class Solution {
    public:

        bool helper(int src, vector<bool>& vis, vector<bool>& recPath,vector<vector<int>>& graph){
            vis[src] = true;
            recPath[src] = true;

            for(int i = 0; i < graph.size(); i++){
                int u = graph[i][1];
                int v = graph[i][0];

                if(src == u){
                    if(!vis[v]){
                        if(helper(v,vis,recPath, graph)){
                            return true;
                        }
                    }else if(recPath[v]){
                        return true;
                    }
                }
            }
            recPath[src] = false;
            return false;
        }
        bool canFinish(int numCourses, vector<vector<int>>& graph) {
            int v = graph.size();

            vector<bool> vis(numCourses,false);
            vector<bool> resPath(numCourses,false);

            for(int i = 0; i < numCourses; i++){
                if(!vis[i]){
                    if(helper(i, vis, resPath , graph)){
                        return false;
                    }
                }
            }
            return true;
            
        }
    };