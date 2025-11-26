class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        //this store the remendair and the freq 
        unordered_map<int, int> f;
        int result = 0;

        f[0] = 1; //this is for empty array
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = ((sum % k) + k) % k;
            
            result += f[rem];
            f[rem] ++;

        }
        return result;

        
    }
};