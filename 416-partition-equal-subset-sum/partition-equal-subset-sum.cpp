class Solution {
public:

    bool targetValue(int index , vector<int> &nums, int targetV , vector<vector<int>> &dp){
        

       
        if(targetV == 0) return true;
        if(index == nums.size()) return false;
        if(dp[index][targetV] != -1) return dp[index][targetV];
        
        bool take = false;
        if(nums[index] <= targetV){
            take = targetValue(index + 1, nums, targetV - nums[index],dp);
        }
        
        bool notTake = targetValue(index + 1, nums, targetV,dp);//Calculate if we not include a number 
    
        return dp[index][targetV] = take || notTake; // return true if any of set find the target value (half of the total sum)

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        


        int totalSum = 0;
        for(int i : nums){ // We have to return if any subset is equal to the half of the total sum like sub1(sum) == sub(sum) == equal 
            totalSum += i; //So we calculate the total sum
        } 

        if(totalSum % 2 != 0){//If sum is odd we can't find the totalsum / 2 
            return false;
        }
       int  targetV = totalSum / 2;//Here we have to find the totalSum / 2 from all the sub sets
       vector<vector<int>> dp(n,vector<int>(targetV + 1,-1));

        return targetValue(0 , nums , targetV,dp);//Here we pass the half value of total sum 
        
    }
};