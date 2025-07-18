class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int totalSize = nums.size();

        // Step 1: Left side - max heap for smallest sum of largest n elements
        vector<long long> leftSums(totalSize, 0);
        priority_queue<int> maxHeap;
        long long sum = 0;

        for (int i = 0; i < 2 * n; ++i) {
            sum += nums[i];
            maxHeap.push(nums[i]);

            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == n)
                leftSums[i] = sum;
        }

        // Step 2: Right side - min heap for largest sum of smallest n elements
        vector<long long> rightSums(totalSize, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;

        for (int i = totalSize - 1; i >= n; --i) {
            sum += nums[i];
            minHeap.push(nums[i]);

            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == n)
                rightSums[i] = sum;
        }

        // Step 3: Find minimum difference
        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            res = min(res, leftSums[i] - rightSums[i + 1]);
        }

        return res;
    }
};
