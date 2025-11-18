class Solution {
public:
    // so here we use kadane algo to find the maxSum and the  minSum
    // in this problem we divid the the solution in two parts
    // case 1 : the ans is not the circular , it lies between the array , the
    // same max Summ case 2 : the max ans is present using the circular , so for
    // that first find the minSum and then substract it form the the whole array
    // sum and we get our ans max the case1 and case 2 solution
    int maxSum(vector<int>& nums) {
        int bestEnding = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            bestEnding = max(bestEnding + nums[i], nums[i]);
            result = max(result, bestEnding);
        }
        return result;
    }
    int minSum(vector<int>& nums) {
        int bestEnding = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            bestEnding = min(bestEnding + nums[i], nums[i]);
            result = min(result, bestEnding);
        }
        return result;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(),nums.end(), 0);
        int case1 = maxSum(nums);
        int case2 = totalSum - minSum(nums);
        //their is a case where the totalSum become -ve then we have to solve this
        if(case1 < 0) return case1;
        return max(case1, case2);
    }
};