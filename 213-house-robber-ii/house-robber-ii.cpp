class Solution {
public:
    int robHelper(vector<int> nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        // If size is less than 2
        if (n == 1) {
            return nums[0];
        }

        // creating the vector to store the possibilites
        vector<int> skipLastHouse(n - 1);
        vector<int> skipFirstHouse(n - 1);

        for (int i = 0; i < n - 1; i++) {
            skipLastHouse[i] = nums[i];
            skipFirstHouse[i] = nums[i + 1];
        }

        int lootSkipLastHouse = robHelper(skipLastHouse);
        int lootSkipFirstHouse = robHelper(skipFirstHouse);

        return max(lootSkipLastHouse, lootSkipFirstHouse);
    }
};