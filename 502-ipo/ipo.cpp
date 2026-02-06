class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();
        vector<vector<int>> store;

        for (int i = 0; i < n; i++) {
            int p = profits[i];
            int c = capital[i];
            store.push_back({c, p});
        }

        sort(store.begin(), store.end());
        priority_queue<int> pq;

        int idx = 0;
        for (int i = 0; i < k; i++) {
            while (idx < n) {
                if (store[idx][0] > w) {
                    break;
                }
                pq.push(store[idx][1]);
                idx++;
            }
            if(pq.empty()){
                return w;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};