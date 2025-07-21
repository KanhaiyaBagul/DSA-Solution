class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int startIdx = 0;
        int endIdx = nums.size() - 1;
        if(target > nums[endIdx]) return endIdx + 1;
        if(target < nums[0]) return 0;

        while(startIdx <= endIdx){
            int mid = startIdx + (endIdx - startIdx) / 2;

            if(target == nums[mid]){
                return mid;
            }else if(nums[mid] > target && nums[mid - 1] < target){
                return mid;
            }
            else if(target < nums[mid]){
                endIdx = mid - 1;
            }else if(target > nums[mid]){
                startIdx = mid + 1;
            }

        }
        return -1;
        
    }
};