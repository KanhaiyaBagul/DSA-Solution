class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false;
        int i = 0;
        while(i + 1 < nums.size() && nums[i] < nums[i+1]){
            i++;
        }

        if(i == 0) return false;

        int peak = i;
        while(i + 1 < nums.size() && nums[i] > nums[i+1]){
            i++;
        }

        if(i == peak || i >= n - 1) return false;

        while(i + 1 < nums.size() && nums[i] < nums[i+1]){
            i++;
        }

        return i == n - 1;

        
    }
};