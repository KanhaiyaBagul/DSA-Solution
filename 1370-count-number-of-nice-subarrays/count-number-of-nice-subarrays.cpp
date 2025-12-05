class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum = 0;

        unordered_map<int,int> freq;

        freq[0] = 1;
        int result = 0;

        for(int i = 0; i < nums.size();i++){
            sum += (nums[i] % 2 == 0) ? 0 : 1;

            int f = freq.count(sum - k) == 0 ? 0 : freq[sum - k];

            result += f;
            freq[sum]++;

        }
        return result;
        
    }
};