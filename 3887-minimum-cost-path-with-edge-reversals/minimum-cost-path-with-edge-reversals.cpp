class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> grid(n);

        for (auto& pair : edges) {
            int u = pair[0];
            int v = pair[1];
            int w = pair[2];

            grid[u].push_back({v, w});

            grid[v].push_back({u, 2 * w});
        }

        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dist(n, INT_MAX);

        pq.push({0, 0});

        dist[0] = 0;

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, w] : grid[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n-1];
    }
};