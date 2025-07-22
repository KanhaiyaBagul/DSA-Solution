class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int , int> freqMap; // create the hash map to store the value and the freq
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int maxSum = 0;
        
        for(int right = 0; right < n; right++){
            freqMap[nums[right]]++;
            sum += nums[right];
            while(left < n && freqMap[nums[right]] > 1){
                sum-=nums[left];
                freqMap[nums[left]]--;
                left++;
            }
            maxSum = max(maxSum , sum); // here we have to calculate the maxSum among all the subarray


        }
        return maxSum;
        
    }
};