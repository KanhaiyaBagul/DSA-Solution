class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>prefix(n+1,0);
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                prefix[i + 1] = prefix[i] + 1;
            }else{
                prefix[i+1] = prefix[i] - 1;
            }
        }

        int ans = 0;
        for(int L = 0; L < n; L++){
            
            for(int R = L; R < n; R++){
                int sum = prefix[R+1] - prefix[L];
                if(sum > 0){
                    ans++;
                }
            }
        }
        return ans;
        
        

        
    }
};