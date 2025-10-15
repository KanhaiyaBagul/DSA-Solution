class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int prev = 0;
        int curr = 1;
        int result = INT_MIN;
        for(int i = 1; i < n; i++){
            
            if(nums[i] > nums[i-1]){
                curr++;
            }else{
                prev = curr;
                curr = 1;
            }
            result = max(result, curr/2);
            result = max(result, min(curr, prev));

        }
        return result;
        
        
    }
};