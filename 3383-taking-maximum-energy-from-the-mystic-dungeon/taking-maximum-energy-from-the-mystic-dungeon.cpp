class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxEnergy = INT_MIN;
        vector<int> dp(n + k + 1,0);
        //instead of using of all condtion  use bootom up approch , start form the last index 
        for(int i = n - 1; i >= 0; i --){
            dp[i] = dp[i+k] + energy[i];
            maxEnergy = max(maxEnergy, dp[i]);
        }
        
        return maxEnergy;
        
    }
};