class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int count = 0;
        int maxLength = 0;

        for(int right = 0; right < n; right ++){
            if(nums[right] == 0){
                count++;
            }

            while(left < n && count > 1){
                if(nums[left] == 0){
                    count--;
                }
                left++;
            }

            maxLength = max(maxLength , right - left);
        }
        return maxLength;
        
    }
};