class Solution {
public:
    int rob(vector<int>& nums) {
        //If only  1 element <just return it
        if(nums.size() < 2){
            return nums[0];
        }
        //Create array to store the maximum loot at each index
        vector<int> dp;
        //Memorize maximum loots at first 2 indexes
        dp.push_back(nums[0]);
        dp.push_back(max(nums[0], nums[1]));

        //Use them to fill complete array
        for(int i = 2; i < nums.size(); i++){
            dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
        }


        return dp[nums.size() - 1];


        
    }
};