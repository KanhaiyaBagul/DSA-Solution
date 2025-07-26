#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        // Step 1: Create an array to store conflict start positions for each end
        vector<vector<int>> conflictAtRight(n + 1);

        for (auto& pair : conflictingPairs) {
            int u = pair[0], v = pair[1];
            int left = min(u, v);
            int right = max(u, v);
            conflictAtRight[right].push_back(left);
        }

        long long baseCount = 0;               // Total valid subarrays without removing any pair
        vector<long long> gain(n + 1, 0);      // gain[i] = how many subarrays we can gain if we remove conflict with i as left

        int maxLeft = 0, secondMaxLeft = 0;

        // Step 2: Loop through each possible subarray end position
        for (int end = 1; end <= n; ++end) {
            // Update the current max and second max conflicting left values
            for (int left : conflictAtRight[end]) {
                if (left > maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                } else if (left > secondMaxLeft) {
                    secondMaxLeft = left;
                }
            }

            // Count valid subarrays ending at this position
            baseCount += max(0, end - maxLeft);

            // If we remove the maxLeft restriction, we gain some subarrays
            if (maxLeft > 0) {
                gain[maxLeft] += (maxLeft - secondMaxLeft);
            }
        }

        // Step 3: Find maximum gain from removing one conflict
        long long bestGain = 0;
        for (long long g : gain) {
            bestGain = max(bestGain, g);
        }

        // Final result = base + best gain by removing 1 pair
        return baseCount + bestGain;
    }
};
