class Solution {
public:
    
    unordered_map<string,int> dp;//this is use to backtrack it
    int helper(int i, vector<int>&A,int target, int sum){
        if(i == A.size()){
            return sum == target ? 1 : 0;
        }

        string key = to_string(i) + "," + to_string(sum);
        if(dp.find(key) != dp.end()) return dp[key]; // if already present then return it
        
        
        int add = helper(i+1,A,target,sum + A[i]);//add
        
        int sub = helper(i+1,A,target,sum - A[i]);//sub

        return dp[key] = add + sub;//return and store in the dp
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0,nums,target, 0);
  
    }
};