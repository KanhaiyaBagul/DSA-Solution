class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        priority_queue<pair<int , int> , vector<pair<int, int>> , greater<pair<int , int >>> pq;
        //(wt , v)

        int src = 0;
        int minCost = 0;

        vector<bool> mst(V,false);// it tracks only goes for one time
        pq.push(make_pair(0,src));//initial condtion for the push element 

        while(pq.size() > 0){
            int u = pq.top().second;//vertex
            int cost = pq.top().first;//weight 

            pq.pop();//pop the loweset  wt having vertex

            if(!mst[u]){//if it is not join
                mst[u] = true;//make it join
                minCost += cost;//add the join

                for(int v = 0; v < V; v++){//go through every neighbour
                    if(u != v){
                        int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                        pq.push(make_pair(wt,v));
                    }
                }

            }


        }
        return minCost;

        
    }
};