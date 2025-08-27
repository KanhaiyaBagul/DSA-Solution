class Solution {
public:
    bool canJump(vector<int>& nums) {
        int finalDestination = nums.size() - 1;

        for(int i = nums.size() - 2 ; i >= 0; i--){
            if(i + nums[i] >= finalDestination){
                finalDestination = i;
            }
        }

        return finalDestination == 0;
    }
};