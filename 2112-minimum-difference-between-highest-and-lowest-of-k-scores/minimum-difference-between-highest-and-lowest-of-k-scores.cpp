class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());

        int left = 0;

        

        for(int i = k - 1; i < nums.size(); i++){
            int low = nums[left];
            int high = nums[i];

            ans = min(ans,high - low);
            left++;
        }
        return ans;


        
        return ans;
    }
};