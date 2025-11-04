class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int> mp;

        for(int i  = 0; i < n; i++){
            int num = nums[i];
            int diff = target - num;

            if(mp.count(diff)){
                return {i,mp[diff]};
            }

            mp[num] = i;

        }
        return{};
        
    }
};