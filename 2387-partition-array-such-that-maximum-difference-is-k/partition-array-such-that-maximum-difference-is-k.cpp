class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {


        int n  = nums.size();
        sort(nums.begin(),nums.end());
        int count = 1;
        int minValue = nums[0];
        for(int i = 0; i < n; i++){
            if(nums[i] - minValue > k){
                minValue = nums[i];
                count ++;
            }
        }
        return count;
        
        
    }
};