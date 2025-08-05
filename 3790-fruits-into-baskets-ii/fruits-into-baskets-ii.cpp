class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);  // Keep track of which baskets are already used
        int unplaced = 0;

        // Iterate through each fruit
        for (int i = 0; i < n; ++i) {
            bool placed = false;

            // Find the leftmost unused basket that can hold this fruit
            for (int j = 0; j < n; ++j) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;  // Mark basket as used
                    placed = true;
                    break;  // Move to next fruit
                }
            }

            // If no suitable basket was found
            if (!placed) {
                unplaced++;
            }
        }

        return unplaced;
    }
};
