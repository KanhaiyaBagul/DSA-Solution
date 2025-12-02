class Solution {
public:
    bool dfs(int i, vector<int>& arr, vector<bool>& vis) {

        if (i < 0 || i >= arr.size() || vis[i]) {
            return false;
        }
        if (arr[i] == 0) {
            return true;
        }

        vis[i] = true;

        

        bool plus = dfs(i + arr[i],arr, vis);
        bool minus = dfs(i - arr[i],arr, vis);
       

        return plus || minus;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);

        return dfs(start, arr, vis);
    }
};