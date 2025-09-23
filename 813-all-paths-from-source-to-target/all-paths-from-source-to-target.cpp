class Solution {
public:

    void pathHelper(int src , int dest, vector<vector<int>>& graph,vector<vector<int>>& result, vector<int>& temp){
        temp.push_back(src);
        if(src == dest){
            result.push_back(temp);
            temp.pop_back();
            return;
        }

        
        

        for(int v : graph[src]){
            
                pathHelper(v, dest,graph, result, temp);
            
        }

        temp.pop_back();
       
    }

    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> result;
        vector<int> temp;
        pathHelper(0,v - 1, graph,result, temp);
        return result;

        
    }
};