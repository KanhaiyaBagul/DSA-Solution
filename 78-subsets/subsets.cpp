#include <vector>
class Solution {
public:

    void subArr(vector<int>& nums , vector<vector<int>>& result , vector<int>temp ){
        int n = nums.size();
        if(n == 0){
            result.push_back(temp);
            return;
        }
        int i = nums[0];
        vector<int> addAll = temp;
        addAll.push_back(i);

        vector<int> sub(nums.begin()+ 1 , nums.end());
        subArr(sub,result, addAll);
        subArr(sub,result, temp);



    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        subArr(nums,result,temp);
        return result;

        


        
    }
};