    //in this question we have to return that if we can take the course 
    //We can attend ,if we do the 2nd course before 1 
    //we have to apply topological sort here , for that we require the Directed Acyclic graph 
    //if the cycle occure then it fail to attend the courses 
    //so here we just have to find it is directed and acyclic 
    class Solution {
    public:

        //helper fun 
        bool helper(int src, vector<bool>& vis, vector<bool>& recPath,vector<vector<int>>& graph){
            vis[src] = true;//mark as visited
            recPath[src] = true;//mark for the cycle

            //go through ever neighbout node
            for(int v : graph[src]){
                if(!vis[v]){//if not visited
                    if(helper(v, vis, recPath, graph)){//if it found the cycle return true
                        return true;
                    }
                }else{
                    //if already visited and present in the recPath that means it is repeated and form the cycle 
                    if(recPath[v]){//then return true
                        return true;
                    }
                }
            }
            recPath[src] = false;//this is for backtrack 
            return false;//if no cycle is found then return false
        }
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            int v = numCourses;

            vector<bool> vis(v,false);//tract for vis nodes
            vector<bool> resPath(v,false);//tract the current path


            vector<vector<int>> graph(numCourses);//this store the proper way of nodes and the neighbours
            for(auto &p : prerequisites){
                int u = p[1];
                int v = p[0];
                graph[u].push_back(v);

            }
            //this loop assure that every node is visited
            for(int i = 0; i < v; i++){
                if(!vis[i]){
                    //call for the helper and check if any cycle occure
                    if(helper(i, vis, resPath , graph)){
                        return false;
                    }
                }
            }
            return true;
            
        }
    };