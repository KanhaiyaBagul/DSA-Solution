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

            for(int v : graph[src]){
                if(!vis[v]){
                    if(helper(v, vis, recPath, graph)){
                        return true;
                    }
                }else{
                    if(recPath[v]){
                        return true;
                    }
                }
            }
            recPath[src] = false;
            return false;
        }
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            int v = numCourses;

            vector<bool> vis(v,false);
            vector<bool> resPath(v,false);


            vector<vector<int>> graph(numCourses);
            for(auto &p : prerequisites){
                int u = p[1];
                int v = p[0];
                graph[u].push_back(v);

            }

            for(int i = 0; i < v; i++){
                if(!vis[i]){
                    if(helper(i, vis, resPath , graph)){
                        return false;
                    }
                }
            }
            return true;
            
        }
    };