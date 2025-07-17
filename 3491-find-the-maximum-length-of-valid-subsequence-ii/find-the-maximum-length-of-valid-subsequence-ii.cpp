class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int modVal = (nums[i] + nums[j]) % k;

                // If we can extend a sequence ending at j with the same mod
                int len = dp[j].count(modVal) ? dp[j][modVal] + 1 : 2;

                // Update dp[i][modVal]
                dp[i][modVal] = max(dp[i][modVal], len);

                // Track the overall maximum
                maxLen = max(maxLen, dp[i][modVal]);
            }
        }

        return maxLen;
    }
};
