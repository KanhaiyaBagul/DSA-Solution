class Solution {
public:
    //use dijkstra here
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        //first we have to built the adjency list for u --- v with the weight 
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &e : times){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v,wt});
        }

        //build a min heap
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> pq;
        pq.push({0,k});//for the initial  condition

        vector<int> dist(n + 1,INT_MAX);// this store the min dist form the src node
        dist[k] = 0; // src node dist form it 

        while(pq.size() > 0){
            int u = pq.top().second;
            pq.pop();

            for(auto &x : adj[u]){
                int v = x.first;
                int wt = x.second;

                if(dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v] , v});
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){//if we can't reach any element , we get know by if any idx reamain INT_MAX then we retur -1
                return -1;
            }

        }

        return *max_element(dist.begin() + 1,dist.end()); // we have to write the min dist to reach every node from the k
    }
};