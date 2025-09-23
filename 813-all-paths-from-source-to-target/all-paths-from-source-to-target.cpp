class Solution {
public:
    void pathHelper(int src, int dest, vector<vector<int>>& graph,
                    vector<vector<int>>& result, vector<int>& temp) {
        temp.push_back(src);//first push to the temp
        if (src == dest) {// if src = dest then push to the result 
            result.push_back(temp);
            temp.pop_back();//for backtracking we have to pop it
            return;
        }
        //loop for every node connected to the src
        for (int v : graph[src]) {

            pathHelper(v, dest, graph, result, temp);
        }

        temp.pop_back();//back track 
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int v = graph.size();//Total number of nodes
        vector<vector<int>> result;//store the final result
        vector<int> temp;//store temp path for every call
        pathHelper(0, v - 1, graph, result, temp);//Helper fun call
        return result;
    }
};