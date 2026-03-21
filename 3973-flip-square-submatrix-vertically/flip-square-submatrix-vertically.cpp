class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
       // vector<vector<int>> result = grid;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < k / 2; i++){//this handels the row 
            for(int j = 0; j < k;j++){//this handels each element to swap in two rows
                swap(grid[x+i][y+j],grid[x + (k-1-i)][y+j]);
            }
        }
        return grid;
        
    }
};