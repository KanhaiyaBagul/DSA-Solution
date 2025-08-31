class Solution {
public:
    // Check if placing 'ch' at (row, col) is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false;        // row check
            if (board[i][col] == ch) return false;        // column check
            int subRow = 3 * (row / 3) + i / 3;           // sub-box row
            int subCol = 3 * (col / 3) + i % 3;           // sub-box col
            if (board[subRow][subCol] == ch) return false;
        }
        return true;
    }

    // Backtracking solver
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {  // empty cell
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, row, col, ch)) {
                            board[row][col] = ch;
                            if (solve(board)) return true;   // solved further
                            board[row][col] = '.';           // backtrack
                        }
                    }
                    return false; // no valid number -> backtrack
                }
            }
        }
        return true; // fully solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
