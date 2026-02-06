class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();
        vector<vector<int>> store;
        //store capital and profit in a 2D vector
        for (int i = 0; i < n; i++) {
            int p = profits[i];
            int c = capital[i];
            store.push_back({c, p});
        }
        //sort the vector
        sort(store.begin(), store.end());
        priority_queue<int> pq;

        int idx = 0;//for index tracking
        //for finding top k elements
        for (int i = 0; i < k; i++) {

            while (idx < n) {
                //if capital is greater than the given w then break it 
                if (store[idx][0] > w) {
                    break;
                }
                //push the profit to the pq that we find the max at the top
                pq.push(store[idx][1]);
                idx++;
            }
            //this handels the edge case , if their is not a single cap is greate that w so the pq remain empty so nothing is to push their so we return from here
            if(pq.empty()){
                return w;
            }
            //add the max profit obtain from the w 
            w += pq.top();
            pq.pop();//pop that profit
        }
        return w;
    }
};