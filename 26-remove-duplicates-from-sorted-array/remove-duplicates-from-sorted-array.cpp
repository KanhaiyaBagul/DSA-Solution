class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        int j = i + 1;
        
        while(j < n){
            if(nums[i] < nums[j]){
                swap(nums[i + 1] , nums[j]);
                
                i++;
            }
            j++;

        }
        return i + 1;
        
    }
};