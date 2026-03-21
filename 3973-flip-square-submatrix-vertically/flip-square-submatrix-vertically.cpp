class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> result = grid;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < k / 2; i++){
            for(int j = 0; j < k;j++){
                swap(result[x+i][y+j],result[x + (k-1-i)][y+j]);
            }
        }
        return result;
        
    }
};