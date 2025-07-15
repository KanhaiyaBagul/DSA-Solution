class Solution {
public:
    int findMin(vector<int>& nums) {

    int result = nums[0];
    int right = nums.size() - 1;
    int left = 0;
     while (left <= right){
        if(nums[left] < nums[right]){
            result = min(result , nums[left]);
            break;
        }

        int mid = (left + right) / 2;
        result = min(result,nums[mid]);

        if(nums[left] <= nums[mid]){
            left = mid + 1;
        }
        else{
            right = mid  - 1;
        }

        
     }
     return result;
        
    }
};