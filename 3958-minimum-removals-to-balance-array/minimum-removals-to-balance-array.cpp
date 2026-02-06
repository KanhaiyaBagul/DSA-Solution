class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(nums.size() == 1){
            return 0;
        }
        sort(nums.begin(),nums.end());

        int i = 0;
        int j = 0;
        int maxLen = 1;
        

        while(i <= j && j < n){

            if(nums[j] <= 1LL * nums[i] * k){
                maxLen = max(maxLen , j - i + 1);
                j++;
            }else{
                i++;
            }
            
        }
        return n - maxLen;       
    }
};