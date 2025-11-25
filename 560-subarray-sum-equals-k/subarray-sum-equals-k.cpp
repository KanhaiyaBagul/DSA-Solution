class Solution {
public:
    //this is solved using the prefix sum
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> f;//it stores the prefix sum for each index i
        int result = 0;

        f[0] = 1;//this is for the empty sub array whose sum is "0"
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            int freq = f.find(sum - k) != f.end() ? f[sum - k] : 0;//if we find the sum - k means theris is a sub array whose equal to the k
            result += freq;//add the freq here 
            f[sum]++;
        }
        return result;
        
    }
};