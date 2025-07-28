class Solution {
public:
    int maxBit(int startIdx , vector<int> &nums,int curror, int maxOr, vector<vector<int>> &dp){
        int n = nums.size();
        //If our index reach to the last and it check if our maxor == curror if it is then reutn the value
        if(startIdx == n){
            return (maxOr == curror ) ? 1: 0; 
        }
        if(dp[startIdx][curror] != -1) return dp[startIdx][curror];//Use to make code effictive
        
        
       int include = maxBit(startIdx + 1 , nums, curror | nums[startIdx],maxOr , dp); // We include an element 

        int exclude = maxBit(startIdx + 1, nums, curror , maxOr ,dp);//We exclude an element

        return dp[startIdx][curror] = include + exclude; //Calculate the finnal result
    
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int startIdx = 0;
        int maxOr = 0;
        //Calculate the first  maxOr of the array
        for(int i : nums){
            maxOr |= i;
        }
        int curror = 0;
        vector<vector<int>> dp(n + 1,vector<int>(maxOr + 1, -1)); //Reuse in recursion
       return maxBit(startIdx,nums,curror,maxOr,dp);
        

        
    }
};