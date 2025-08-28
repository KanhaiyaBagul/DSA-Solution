class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> mp;

        // Step 1: Collect all diagonals using key = (i - j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(grid[i][j]);
            }
        }

        // Step 2: Sort each diagonal according to rules
        for (auto &p : mp) {
            if (p.first >= 0) {
                // bottom-left (including main diagonal) -> non-increasing
                sort(p.second.begin(), p.second.end(), greater<int>());
            } else {
                // top-right -> non-decreasing
                sort(p.second.begin(), p.second.end());
            }
        }

        // Step 3: Place sorted values back into grid
        unordered_map<int, int> idx;  // keeps track of index for each diagonal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = mp[key][idx[key]++];
            }
        }

        return grid;
    }
};
