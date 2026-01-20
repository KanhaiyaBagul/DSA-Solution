class Solution {
public:
    int helper(int mid ,vector<vector<int>> &matrix){
        int row = matrix.size() - 1;
        int col = 0;
        int count = 0;

        while(row >= 0 && col < matrix[0].size()){
            if(matrix[row][col] > mid){
                row--;
            }else{
                count += row + 1;
                col++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n-1][m-1];
        int ans = -1;


        while(low <= high){
            int mid = low + (high - low) / 2;

            if(helper(mid,matrix) >= k){
                ans = mid;

                high = mid - 1;

            }else{
                low = mid + 1;
            }
        }
        return ans;
        
    }
};