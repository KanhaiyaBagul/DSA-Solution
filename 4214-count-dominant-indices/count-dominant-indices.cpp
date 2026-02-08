class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int count = 0;
        int deno = n - 1;

        for(int i = 0; i < n - 1; i++){
            totalSum -= nums[i];

            double avg = (double)totalSum / deno;
            deno--;
            if(nums[i] > avg){
                count++;
            }

        }
        return count;
        
    }
};