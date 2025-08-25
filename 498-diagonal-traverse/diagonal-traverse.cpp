class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);

        // Traverse over all possible diagonals
        for (int d = 0; d < m + n - 1; d++) {
            vector<int> intermediate;
            // starting point of this diagonal
            int r = (d < n) ? 0 : d - n + 1;
            int c = (d < n) ? d : n - 1;

            // collect all elements in this diagonal
            while (r < m && c >= 0) {
                intermediate.push_back(mat[r][c]);
                r++;
                c--;
            }

            // reverse every alternate diagonal
            if (d % 2 == 0) {
                reverse(intermediate.begin(), intermediate.end());
            }

            // add collected diagonal to result
            result.insert(result.end(), intermediate.begin(), intermediate.end());
        }
        return result;
    }
};
