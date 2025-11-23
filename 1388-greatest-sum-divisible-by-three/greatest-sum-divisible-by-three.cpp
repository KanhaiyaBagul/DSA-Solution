class Solution {
public:
    int helper(int i, vector<int>& nums, int rem,vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return rem == 0? 0 : INT_MIN;
        }

        if(dp[i][rem] != -1) return dp[i][rem];

        

       int include =  nums[i] + helper(i + 1, nums,(rem + nums[i])%3,dp);
    
        int exclusive = helper(i + 1, nums, rem, dp);

        return dp[i][rem] = max(include, exclusive);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3,-1));
        int rem = 0;
        
        return helper(0, nums, rem , dp);
        
    }
};