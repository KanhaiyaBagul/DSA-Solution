class Solution {
public:
    long long maxSum(vector<int>& nums) {
        // Handle the edge case where all numbers are non-positive
        // The problem states the resulting subarray must be non-empty.
        // If all numbers are non-positive, the maximum sum is simply the
        // largest (least negative or zero) single element.
        long long max_val = -2e18; // Initialize with a very small number
        bool all_non_positive = true;

        for (int num : nums) {
            if (num > 0) {
                all_non_positive = false;
            }
            max_val = max(max_val, (long long)num);
        }

        if (all_non_positive) {
            return max_val;
        }

        // Collect unique positive numbers and sum them
        unordered_set<int> unique_elements;
        long long current_sum = 0;

        for (int num : nums) {
            if (num > 0 && unique_elements.find(num) == unique_elements.end()) {
                current_sum += num;
                unique_elements.insert(num);
            }
        }
        
        return current_sum;
    }
};