class Solution {
public:
    vector<vector<int>> tree;
    vector<int> subtreeXor, in, out;
    int timer = 0, totalXor = 0;

    void dfs(int node, int parent, const vector<int>& nums) {
        in[node] = timer++;
        subtreeXor[node] = nums[node];

        for (int child : tree[node]) {
            if (child == parent) continue;
            dfs(child, node, nums);
            subtreeXor[node] ^= subtreeXor[child];
        }

        out[node] = timer++;
    }

    // Check if u is ancestor of v using entry/exit times
    bool isAncestor(int u, int v) {
        return in[u] <= in[v] && out[u] >= out[v];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, {});
        subtreeXor.resize(n);
        in.resize(n);
        out.resize(n);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        dfs(0, -1, nums);
        totalXor = subtreeXor[0];

        int result = INT_MAX;

        // Consider every pair of edges as removed
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = i, b = j;

                // Let’s assume we remove the edge between a and its parent
                // and the edge between b and its parent
                if (isAncestor(a, b)) {
                    int xor1 = subtreeXor[b];
                    int xor2 = subtreeXor[a] ^ xor1;
                    int xor3 = totalXor ^ subtreeXor[a];
                    result = min(result, max({xor1, xor2, xor3}) - min({xor1, xor2, xor3}));
                }
                else if (isAncestor(b, a)) {
                    int xor1 = subtreeXor[a];
                    int xor2 = subtreeXor[b] ^ xor1;
                    int xor3 = totalXor ^ subtreeXor[b];
                    result = min(result, max({xor1, xor2, xor3}) - min({xor1, xor2, xor3}));
                }
                else {
                    int xor1 = subtreeXor[a];
                    int xor2 = subtreeXor[b];
                    int xor3 = totalXor ^ xor1 ^ xor2;
                    result = min(result, max({xor1, xor2, xor3}) - min({xor1, xor2, xor3}));
                }
            }
        }

        return result;
    }
};
