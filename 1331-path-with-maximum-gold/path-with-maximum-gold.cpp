class Solution {
public:
    
    
    void gold(int m, int n,int i, int j,vector<vector<int>> &grid ,int currGold , int &maxGold){
        
        if(i < 0 || j < 0 || i == m || j == n || grid[i][j] == 0){ // base case if i and j are outof bound and if the element is zero or it is visited reutun the call
            
            return;
        }

        int heregold = grid[i][j];
        currGold += heregold;
        maxGold = max(maxGold , currGold);

        grid[i][j] = 0;

        gold(m, n , i - 1,j,grid, currGold,maxGold); //Upward
        gold(m, n , i + 1,j,grid, currGold,maxGold);//down
        gold(m, n , i,j + 1,grid, currGold,maxGold);//right
        gold(m, n , i,j - 1,grid, currGold,maxGold);//left

        grid[i][j] = heregold;// main backtracking logic
    }

    
    int getMaximumGold(vector<vector<int>>& grid) {
        int currGold = 0;
        int maxGold = 0;
        int m = grid.size();
        int n = grid[0].size();

        //calculate the maxGold starting at any point in matrix
        for(int i = 0; i < m ;i ++){
            for(int j = 0; j < n ;  j++){
                if(grid[i][j] > 0){
                    gold(m, n , i , j, grid, currGold,maxGold);
                }
            }
        }
        
    return maxGold;

        
    }
};