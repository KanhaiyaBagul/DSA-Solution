class Solution {
public:
    //using kadang algo 
    //calculate the minsum of the whole array
    int minSum(vector<int> & nums){
        
        int bestEnding = nums[0];
        int result = nums[0];

        for(int i = 1; i < nums.size(); i++){
            bestEnding =  min(bestEnding + nums[i], nums[i]);
            result = min(result, bestEnding);
        }
        return result;
    }
    //calculate maxSum of array
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
        //here we calculate the max Sum and the min sum of the array 
        //and compair which is the max 
        return max(maxSum(nums), abs(minSum(nums)));
        
    }
};