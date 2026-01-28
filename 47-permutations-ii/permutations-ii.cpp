class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& nums, int i, vector<int>& curr,
                vector<bool>& use) {

        if (i >= nums.size()) {
            result.push_back(curr);
            return;
        }

        for (int j = 0; j < nums.size(); j++) {
            
            if(use[j]) continue;
            //this condition is for if the prev element is not visited them we can't vist the element after that  so we skip it 
            if(j > 0 && nums[j] == nums[j-1] && !use[j-1]){
                continue;
            }

            use[j] = true;
            curr.push_back(nums[j]);
            helper(nums, i + 1, curr, use);
            curr.pop_back();
            use[j] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> use(n,false);
        vector<int> curr;

        helper(nums,0,curr,use);
        return result;
    }
};