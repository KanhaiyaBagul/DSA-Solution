class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int start = 0;
        int end = nums.size() - 1;
        int result = INT_MIN;

        while(start < end){

            result = max(result,(nums[start]+nums[end]));

            start++;
            end--;

        }
        return result;
    }
};