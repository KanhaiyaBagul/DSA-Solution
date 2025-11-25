class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> f;
        int result = 0;

        f[0] = 1;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            int freq = f.find(sum - k) != f.end() ? f[sum - k] : 0;
            result += freq;
            f[sum]++;
        }
        return result;
        
    }
};