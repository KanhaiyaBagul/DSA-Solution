class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        //we check where it break the sorted order
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]){
                count++;
            }
        }

        //if whole array is rotated but not rotated means we apply 0 rotations
        if(nums[n - 1] > nums[0]){
            count++;
        }

        return count <= 1;

        
    }
};