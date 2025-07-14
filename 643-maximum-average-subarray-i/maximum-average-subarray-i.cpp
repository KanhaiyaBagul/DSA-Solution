class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        double maxAvg = 0;
        int sum = 0;
        int maxSum = 0;
        
        double avg = 0;
        int left = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
            maxSum = sum;

        
        for(int i = k; i < n; i++){
            sum = sum + nums[i] - nums[i - k];
            maxSum = max(maxSum,sum);

        }
        maxAvg = static_cast<double>(maxSum) / k;

        
        return maxAvg;
       
    }
};