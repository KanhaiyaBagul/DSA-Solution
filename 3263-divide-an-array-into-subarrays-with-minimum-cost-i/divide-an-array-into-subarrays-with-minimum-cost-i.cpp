class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int ans = nums[0];
        sort(nums.begin() + 1, nums.end());

        for(int i = 1; i <=2 ; i++){
            ans += nums[i];
        }
        return ans;
        
    }
};