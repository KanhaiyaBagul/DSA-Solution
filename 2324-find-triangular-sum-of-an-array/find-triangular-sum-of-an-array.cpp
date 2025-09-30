class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        //this loop for the size of nums to become 1
        while(nums.size() != 1){
            int n = nums.size();
            //this traves through every time
            for(int i = 0; i < n - 1; i++){
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums.pop_back();
        }
        return nums[0];
        
    }
};