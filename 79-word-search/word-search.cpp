class Solution {
public:
    bool search(int i, int j, vector<vector<char>>& board, string word,
                int index) {
        int m = board.size();
        int n = board[0].size();

        if (index == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= m || j >= n || (board[i][j] == '.') ||
            board[i][j] != word[index]) {
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '.';

        bool result = (search(i - 1, j, board, word, index + 1) ||
                       search(i + 1, j, board, word, index + 1) ||
                       search(i, j - 1, board, word, index + 1) ||
                       search(i, j + 1, board, word, index + 1));

        board[i][j] = ch;

        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int index = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (search(i, j, board, word, index)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};