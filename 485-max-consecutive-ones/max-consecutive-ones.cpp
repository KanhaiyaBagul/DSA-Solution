class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        int curr = 0;
        for (int i = 0; i < n; i++) {

            if (nums[i] != 1) {
                curr = 0;
            }
            else {
                curr++;
            }
            result = max(result, curr);
        }

        return result;
    }
};