class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = INT_MAX;
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            result = min(result , nums[mid]);
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return result;
        
    }
};