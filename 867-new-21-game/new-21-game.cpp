class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0; 

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double W = 1.0, result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = W / maxPts;

            if (i < k) W += dp[i]; // Alice can continue drawing
            else result += dp[i];  // Alice stops here

            if (i - maxPts >= 0) W -= dp[i - maxPts]; // slide window
        }
        return result;
    }
};
