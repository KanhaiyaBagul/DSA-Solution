
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;        // Final result set
        unordered_set<int> cur;        // OR values ending at current index

        for (int x : arr) {
            unordered_set<int> next;
            next.insert(x); // New subarray starting at x

            for (int val : cur) {
                next.insert(val | x); // Extend previous subarrays
            }

            cur = next; // Move forward
            res.insert(cur.begin(), cur.end()); // Collect results
        }

        return res.size();
    }
};
