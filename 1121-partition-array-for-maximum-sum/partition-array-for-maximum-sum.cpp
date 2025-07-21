class Solution {
public:

    //We have to write the recursion fun to find all the possiblity
    int maxSum(vector<int> &arr, int startIdx, int k,vector<int> &dp){
        int n = arr.size();

        if(startIdx == arr.size()) return 0; // Base case to stop the recursion

        if(dp[startIdx] != -1) return dp[startIdx]; // If any of the start value is repeated are calculated previously we store in the dp and we use when the same value is occure 

        int length = 0;
        int maxSubValue = INT_MIN;
        int maxResult = INT_MIN;

        for(int i = startIdx; i < min(startIdx + k, n); i++){
            length++; // Use to determine the size of the array lenght , it is work like window size 
            
            maxSubValue = max(maxSubValue, arr[i]); // It is use to find the max value from the sub array 

            int maxValue = length * maxSubValue + maxSum(arr,i + 1,k,dp); // Here we calculate the OTHER HALF of the array

            maxResult = max(maxResult,maxValue); // Here we calculate the value that we are getting from the whole array;   It calculate all the probable value and find the MAX from it
        }
        return dp[startIdx] = maxResult;//This is final result of our problem and 

    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> dp(n,-1);

        return maxSum(arr,0, k,dp);
        
    }
};