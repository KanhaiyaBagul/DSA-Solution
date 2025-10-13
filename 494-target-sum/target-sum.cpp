class Solution {
public:
    
    unordered_map<string,int> dp;
    int helper(int i, vector<int>&A,int target, int sum){
        if(i == A.size()){
            return sum == target ? 1 : 0;
        }

        string key = to_string(i) + "," + to_string(sum);
        if(dp.find(key) != dp.end()) return dp[key];
        
        
        int add = helper(i+1,A,target,sum + A[i]);
        
        int sub = helper(i+1,A,target,sum - A[i]);

        return dp[key] = add + sub;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0,nums,target, 0);
  
    }
};