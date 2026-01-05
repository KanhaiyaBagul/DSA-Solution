class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negCount = 0;
        int minAbs = INT_MAX;
        long long totalSum = 0;
        

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                int val = matrix[i][j];
                if(val < 0) negCount++;
                totalSum += abs(val);

                minAbs = min(minAbs, abs(val));

            }
        }
        if(negCount % 2 == 0){
            return totalSum;
        }else{
            return totalSum - 2 * minAbs;
        }


    }
};