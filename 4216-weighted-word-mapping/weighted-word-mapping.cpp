class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (auto& str : words) {
            int sum = 0;
            for (auto& ch : str) {
                sum += weights[ch - 'a'];
            }
            sum = sum % 26;
            result += 'z' - sum;
        }
        return result;
    }
};