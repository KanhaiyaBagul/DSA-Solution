#include <vector>
using namespace std;

class Solution {
public:
    void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if we've considered all elements
        if (index == nums.size()) {
            result.push_back(current);  // Save the current subset
            return;
        }

        // 1️⃣ Include nums[index] in the current subset
        current.push_back(nums[index]);
        generateSubsets(index + 1, nums, current, result);

        // 2️⃣ Exclude nums[index] from the current subset (backtrack)
        current.pop_back();
        generateSubsets(index + 1, nums, current, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // To store all subsets
        vector<int> current;         // Current subset being formed
        generateSubsets(0, nums, current, result);
        return result;
    }
};
