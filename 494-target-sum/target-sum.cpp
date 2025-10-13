class Solution {
public:
    int count = 0;
    void helper(int i, vector<int>&A,int target, int sum){
        if(sum != target && i == A.size()){
            return;
        }
        if(i == A.size() && sum == target){
            count++;
            return;
        }
        
        helper(i+1,A,target,sum + A[i]);
        
        helper(i+1,A,target,sum - A[i]);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(0,nums,target, 0);
        return count;
        
    }
};