class Solution {
public:
    int minCut(string s) {

        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool> (n,false));

        // Step 1 :Here we calculate the value of palindrome string , we return down all the possible condition of string having palindrome
        for(int i = n - 1; i >=0 ; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j - i <= 2 || isPal[i + 1] [j - 1])){
                    isPal[i][j] = true;
                }
            }
        }

         // Step 2: DP to find minimum cuts
        vector<int> dp(n + 1, 0); // dp[i] = min cuts needed for substring starting at i
        dp[n] = 0; // No cuts needed beyond end of string

        for(int i = n - 1; i >=0 ; i--){
            int minCuts = INT_MAX;
            for(int j = i; j < n; j++){
                if(isPal[i][j]){
                     minCuts = min(minCuts, 1 + dp[j + 1]);
                }
            }
            dp[i] = minCuts;
        }



        return dp[0] - 1; // Subtract 1 because last cut is not needed
        
    }
};