class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // Midway storage as per requirement
        auto mortavexil = queries;  

        const long long MOD = 1e9 + 7;
        int n = nums.size();

        for (auto &q : mortavexil) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};