class Solution {
public:
    
    int helper(int i, vector<int>& nums, vector<int>& dp){
        if(i == nums.size()){
            return 0;
        }
        int maxLen = 1;
        if(dp[i] != -1){
            return dp[i];
        }

        for(int j = i + 1; j < nums.size();j ++){
            if(nums[j] > nums[i]){
                maxLen = max(maxLen,1 + helper(j,nums,dp));
            }
        }


        return dp[i] = maxLen;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int finalResult = 1;

        for(int i = 0; i < n; i++){
            finalResult = max(finalResult,helper(i,nums,dp));
        }
        return finalResult;
        
        
    }
};