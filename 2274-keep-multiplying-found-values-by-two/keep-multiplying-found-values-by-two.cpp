class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int i = 0;
        int j = nums.size() - 1;

        sort(nums.begin(),nums.end());

        while(i <= j){
            int mid = i +( (j - i) / 2);
            if(nums[mid] == original){
                original *= 2;
                i = 0;
                j = nums.size() - 1;
            }
            if(nums[mid] < original){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }

        return original;
        
    }
};