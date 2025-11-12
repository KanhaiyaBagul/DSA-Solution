class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int countOne = count(nums.begin(), nums.end(), 1);

        if(countOne > 0){
            return n - countOne;
        }

        int minLen = INT_MAX;
        bool flag = false;
        for(int i = 0; i < n - 1; i++){
            int g = nums[i];
            for(int j = i + 1; j < n; j++){
                g = gcd(g,nums[j]);

                if(g == 1){
                    minLen = min(minLen,j - i + 1);
                    flag = true;
                    break;
                }
            }
        }

        if(flag){
            return (minLen - 1) + (n - 1);
        }else{
            return -1;
        }



        

        
        
    }
};