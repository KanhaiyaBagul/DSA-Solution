class Solution {
public:
    int maximumLength(vector<int>& A, int k) {
        int res = 0;
        for (int v = 0; v < k; v++) {
            vector<int> dp(k);
            for (int a : A) {
                dp[a % k] = dp[(v + k - a % k) % k] + 1;
                res = max(res, dp[a % k]);
            }
        }
        return res;
    }
};