class Solution {
public:

// Helper function to solve the linear version of the problem
// i.e when houses are not arranged in a cirle
    int robHelper(vector<int> nums) {
        int n = nums.size();

        // Base case : no house to rob
        if (n == 0)
            return 0;

        //Base case : only one house to rob
        if (n == 1)
            return nums[0];

        //DP array to store max loot up to each house    

        vector<int> dp(n);
        dp[0] = nums[0]; // rob the first house
        dp[1] = max(dp[0], nums[1]);//max of robbing 1st or 2nd house


        // Fill dp[i] using the choice  : rob current of skip it
        for (int i = 2; i < n; i++) {
            //Either rob current house + dp[i - 2] or skip current 
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        //The last element contains the answer for this linear case
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

        //Call helper on both cases and return the maximum loot possible
        int lootSkipLastHouse = robHelper(skipLastHouse);
        int lootSkipFirstHouse = robHelper(skipFirstHouse);

        return max(lootSkipLastHouse, lootSkipFirstHouse);
    }
};