class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int sr,er,sc,ec;
        sr = 0;
        er = n -1;
        sc = 0;
        ec = n - 1;

        while(sr<er){
            for(int i = 0 ;i < (er -sr); i++){

                int temp = matrix[sr][sc + i];
                matrix[sr][sc + i] = matrix[er - i][sc];

                matrix[er - i][sc] = matrix[er][ec - i];

                matrix[er][ec - i] = matrix[sr + i][ec];

                matrix[sr + i][ec] = temp;   
            }

            sr++;
            sc++;
            ec--;
            er--;
        }
        

        
    }
};