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
            if(diff == 0) {//if difference is zero then the zeros and one are same 
                maxLen = max(maxLen , i + 1);
                continue;
            }

            if(f.find(diff) != f.end()){//in here if we find the same difference then difinetly their is a same amount of one and zero's are present we find the index between them and store it
                maxLen = max(maxLen, i - f[diff]);
            }else{
                f[diff] = i;
            }

            

        }
        return maxLen;
        
        
    }
};