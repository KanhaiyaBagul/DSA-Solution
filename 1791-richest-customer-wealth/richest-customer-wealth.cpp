class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int i = accounts.size();
        int j = accounts[0].size();
        
        int maxSum = 0;

        for(int i = 0; i < accounts.size(); i ++){
            int currSum = 0;
            for(int j = 0; j < accounts[0].size(); j++){
                currSum += accounts[i][j];
                

            }
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
        
    }
};