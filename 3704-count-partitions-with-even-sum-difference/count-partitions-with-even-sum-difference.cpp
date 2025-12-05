class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        int result = 0;

        for(int num : nums) totalSum += num;

        
        int sum = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            sum += nums[i];

            int left = totalSum - sum;

            if(abs(sum - left) % 2 == 0){
                result++;
            }

        }
        return result == -1 ? 0 : result;
        
    }
};