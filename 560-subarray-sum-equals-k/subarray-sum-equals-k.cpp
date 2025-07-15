class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        

        int n = nums.size();
        
        int count = 0;
        
        for(int i = 0; i < n ; i ++){
            int sum = 0;
            int j = i;
            while(j < n){
                sum += nums[j];
                if(sum == k){
                    count++;
                    
                }
                j++;

            }
        }
        return count;
        
    }
};