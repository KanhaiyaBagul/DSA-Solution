class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int sum = INT_MIN;
        int currSum = 0;

        for(int i = 0; i < n; i++){
            if(currSum < 0){
                currSum = 0;
            }
            currSum += nums[i];
            sum = max(currSum, sum);

        }
        return sum;
        
    }
};