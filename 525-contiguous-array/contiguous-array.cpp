class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;
        int maxLen = 0;
        unordered_map<int,int> f;

        for(int i = 0; i < n ; i++){
            if(nums[i] == 0){
                zero++;
            }else{
                one++;
            }

            int diff = zero - one;
            if(diff == 0) {
                maxLen = max(maxLen , i + 1);
                continue;
            }

            if(f.find(diff) != f.end()){
                maxLen = max(maxLen, i - f[diff]);
            }else{
                f[diff] = i;
            }

            

        }
        return maxLen;
        
        
    }
};