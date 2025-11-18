class Solution {
public:

    int minSum(vector<int> & nums){
        
        int bestEnding = nums[0];
        int result = nums[0];

        for(int i = 1; i < nums.size(); i++){
            bestEnding =  min(bestEnding + nums[i], nums[i]);
            result = min(result, bestEnding);
        }
        return result;
    }
    int maxSum(vector<int> & nums){
        int bestEnding = nums[0];
        int result = nums[0];

        for(int i = 1; i < nums.size(); i++){
            bestEnding =  max(bestEnding + nums[i], nums[i]);
            result = max(result, bestEnding);
        }
        return result;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        return max(maxSum(nums), abs(minSum(nums)));
        
    }
};