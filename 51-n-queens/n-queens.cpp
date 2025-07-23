class Solution {
public:
    void nQueen(int index, vector<string>& queen,
                vector<vector<string>>& result, vector<int>& col,
                vector<int>& rDiago, vector<int>& lDiago) {
        int n = queen.size();

        if (index == queen.size()) {//This is base case if we reach the last index means the last row then we return 
            result.push_back(queen);
            return;
        }



        for (int j = 0; j < queen.size(); j++) { // This for loop is use to determine which colum wil have the Q

            if (col[j] && rDiago[index + j] && lDiago[index - j + n - 1]) {// This condition check whether we put Q or not
                queen[index][j] = 'Q';
                col[j] = rDiago[index + j] = lDiago[index - j + n - 1] = 0; // set the valid position that the row colum and diagonal are accopie

                nQueen(index + 1, queen, result, col, rDiago, lDiago); //call for next possible place where we put the Q

                queen[index][j] = '.'; // After the above fun is return means the result is store remove this possibility and find the other possibility
                col[j] = rDiago[index + j] = lDiago[index - j + n - 1] = 1;//this update the checks
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queen(n, string(n, '.'));//make sample queen matrix

        vector<vector<string>> result; //Use to store result
        vector<int> col(2 * n - 1, 1);//Use to find the valid places to put Q
        vector<int> rDiago(2 * n - 1, 1);//Use to find the valid places to put Q
        vector<int> lDiago(2 * n - 1, 1);//Use to find the valid places to put Q

        nQueen(0, queen, result, col, rDiago, lDiago);
        return result;
    }
};