class Solution {
public:

    bool recursion(int i, vector<int>& nums, int target , vector<vector<int>>& dp){
        if(target == 0){//if target becomes 0
            return true;
        }

        if(i == nums.size()){// if reach to the last index
            return false;
        }

        if(dp[i][target] != -1){//if we already calculated
            return dp[i][target];
        }

        bool take = false;
        if(nums[i] <= target){//this is for if the nums is less that the target then we can't find the partion
            take = recursion(i  + 1, nums, target - nums[i],dp);
        }

        bool notTake = recursion(i + 1, nums, target, dp);//not included

        return dp[i][target] = take || notTake;//the dp
    } 
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i : nums){
            sum += i;
        }

        if(sum % 2 != 0){
            return false;
        }
        int target = sum / 2;

        vector<vector<int>> dp(n + 1,vector<int> (target+ 1,-1));

        return recursion(0,nums,target,dp);


        
    }
};