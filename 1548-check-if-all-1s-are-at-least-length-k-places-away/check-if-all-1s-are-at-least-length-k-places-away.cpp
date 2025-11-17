class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int gap = k;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                gap++;
            }else if(nums[i] == 1 && gap >= k){
                gap = 0;
            }else if(nums[i] == 1 && gap < k){
                return false;
            }
        }
        return true;
        
    }
};