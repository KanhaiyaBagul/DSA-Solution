class Solution {
public:
    class Info {
    public:
        int u;
        int cost;
        int stops;

        Info(int u, int cost, int stops) {
            this->u = u;
            this->cost = cost;
            this->stops = stops;
        }
    };
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        queue<Info> q;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        q.push(Info(src, 0, -1));

        //this is a bfs approch 
        while (q.size() > 0) {
            Info curr = q.front();
            q.pop();

            for (int i = 0; i < flights.size(); i++) {//traverse through all the sourse to dest
                if (flights[i][0] == curr.u) {//if it starts from our src like the parent 

                    int v = flights[i][1];//store the dest
                    int wt = flights[i][2];//weight of the u ---> v

                    if (dist[v] > curr.cost + wt && curr.stops + 1 <= k) {//if they are in the mention conditon then it replace with the smaller cost
                        dist[v] = curr.cost + wt;// main edge relaction 
                        q.push(Info(v, dist[v], curr.stops + 1));//push the child to the queue 
                    }
                }
            }
        }
        //if we never found the path to the dst within the proper condition
        if (dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];
    }
};