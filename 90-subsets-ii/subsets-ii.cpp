class Solution {
public:

    void sub(int index , vector<int> &nums,vector<int> current,vector<vector<int>> & result){


        
            result.push_back(current);
            

        
            for(int i = index ; i < nums.size(); i++){

                if(i > index && nums[i] == nums[i - 1] ) continue;

                current.push_back(nums[i]);
                sub(i + 1, nums, current, result);
                current.pop_back();
                
            }

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> current;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());//Use to sort the nums
        sub(0, nums, current , result);
        return result;
        
    }
};