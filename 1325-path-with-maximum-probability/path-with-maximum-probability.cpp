class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double result = 0;
        

        //first we have to build a edge list undirected
        vector<vector<pair<int,double>>> adj(n);

        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        using P = pair<double,int>;
        priority_queue<P> pq;

        vector<double> dist(n,0.0);
        dist[start_node] = 1.0;
        pq.push({1.0,start_node});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int u = curr.second;
            double prob_u = curr.first;

            if(u == end_node){
                return prob_u;
            }

            for(auto pair : adj[u]){
                int v = pair.first;
                double prob_v= pair.second;
                
                double newProb = dist[u] * prob_v;
                

                if(dist[v] < newProb){
                    dist[v] = newProb;
                    pq.push({newProb,v});
                }


            }
        }
        return 0.0;





        
    }
};