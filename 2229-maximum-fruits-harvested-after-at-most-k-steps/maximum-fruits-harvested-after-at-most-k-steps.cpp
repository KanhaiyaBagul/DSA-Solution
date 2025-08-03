class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, total = 0, maxFruit = 0;

        for (int right = 0; right < n; ++right) {
            total += fruits[right][1];  // Add current fruit amount

            // Try to shrink the window from the left if steps exceed k
            while (left <= right) {
                int leftPos = fruits[left][0];
                int rightPos = fruits[right][0];

                int steps = min(
                    abs(startPos - leftPos) + (rightPos - leftPos),
                    abs(rightPos - startPos) + (rightPos - leftPos)
                );

                if (steps > k) {
                    total -= fruits[left][1];
                    ++left;
                } else {
                    break;
                }
            }

            maxFruit = max(maxFruit, total);
        }

        return maxFruit;
    }
};
