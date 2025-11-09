class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //in this problem we have to find min len of array which sum is greater than target
        int n = nums.size();
        int left = 0;
        //we find the right condition, like first find the sum which is greater or equal to the target here, then try to shrink the solution window if it strinke then calculate the new minLen
        int sum = 0;
        int minLen = INT_MAX;
        for(int right = 0; right < n; right++){
            sum += nums[right];

            while(sum >= target){
                sum-=nums[left];
                minLen = min(minLen,right - left + 1);
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
        
    }
};