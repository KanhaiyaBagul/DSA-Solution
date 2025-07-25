class Solution {
public:
    void comb(int start, int k, int n, vector<int>& current,
              vector<vector<int>>& result) {
        if (current.size() == k && n == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= 9; i++) {

            if (n - i < 0){
             break;
            }
               
            current.push_back(i);
            comb(i + 1, k, n - i, current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> current;
        vector<vector<int>> result;
        int start = 1;
        comb(start, k, n, current, result);
        return result;
    }
};