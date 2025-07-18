

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int totalSize = nums.size();

        // Left side: min heap to keep track of the smallest n elements in the first 2n elements
        vector<long long> leftSums(totalSize, 0);
        priority_queue<int> maxHeap; // max heap to remove largest elements
        long long sum = 0;

        for (int i = 0; i < 2 * n; ++i) {
            sum += nums[i];
            maxHeap.push(nums[i]);

            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == n) {
                leftSums[i] = sum;
            }
        }

        // Right side: max heap to keep track of the largest n elements in the last 2n elements
        vector<long long> rightSums(totalSize, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap; // min heap to remove smallest elements
        sum = 0;

        for (int i = totalSize - 1; i >= n; --i) {
            sum += nums[i];
            minHeap.push(nums[i]);

            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == n) {
                rightSums[i] = sum;
            }
        }

        // Find the minimum difference
        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            res = min(res, leftSums[i] - rightSums[i + 1]);
        }

        return res;
    }
};