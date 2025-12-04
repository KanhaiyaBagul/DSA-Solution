class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int zero = 0;
        int one = 0;
        int two = 0;

        for(int num : nums){
            if(num == 0) zero++;
            else if(num == 1) one++;
            else two ++;
        }

        int idx = 0;
        for(int i = 0; i < zero; i++){
            nums[idx] = 0;
            idx++;
        }
        for(int i = 0; i < one; i++){
            nums[idx] = 1;
            idx++;
        }
        for(int i = 0; i < two; i++){
            nums[idx] = 2;
            idx++;
        }
        
    }
};