class Solution {
public:
    int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0); // dp[i] = number of people who learned the secret on day i
        dp[1] = 1; // first person learns the secret on day 1

        for (int day = 2; day <= n; day++) {
            for (int prev = max(1, day - forget + 1); prev <= day - delay; prev++) {
                dp[day] = (dp[day] + dp[prev]) % mod;
            }
        }

        // count people who still know the secret on day n
        long long result = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if(day >= 1)
                result = (result + dp[day]) % mod;
        }

        return (int)result;
    }
};
