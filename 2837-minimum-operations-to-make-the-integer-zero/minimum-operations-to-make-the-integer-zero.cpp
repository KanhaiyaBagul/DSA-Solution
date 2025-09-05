class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        for (int k = 1; k <= 60; ++k) {
            long long x = num1 - (long long)k * num2;
            
            // Condition 1: The target value must be at least the number of operations.
            if (x < k) {
                continue;
            }
            
            // Count the number of set bits (popcount).
            int set_bits = 0;
            long long temp_x = x;
            while(temp_x > 0) {
                set_bits += (temp_x & 1);
                temp_x >>= 1;
            }
            
            // Condition 2: The popcount must be less than or equal to k.
            if (set_bits <= k) {
                return k;
            }
        }
        
        return -1;
    }
};