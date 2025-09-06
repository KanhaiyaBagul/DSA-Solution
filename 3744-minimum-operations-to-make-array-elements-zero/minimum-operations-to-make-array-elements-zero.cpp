#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long calculateTotalSingleOps(long long n) {
        if (n <= 0) {
            return 0;
        }

        long long total_ops = 0;
        long long power_of_4 = 1;
        int k = 0; // Represents the exponent of 4 (e.g., 4^k)
        
        while (true) {
            long long next_power_of_4 = power_of_4 * 4;
            
            // Check for potential overflow of next_power_of_4
            if (next_power_of_4 / 4 != power_of_4) {
                next_power_of_4 = -1; // Indicate overflow
            }

            long long end_of_range = (next_power_of_4 == -1) ? -1 : (next_power_of_4 - 1);
            
            long long count;
            if (end_of_range != -1) {
                count = min(end_of_range, n) - (power_of_4 - 1);
            } else {
                count = n - (power_of_4 - 1);
            }
            
            if (count > 0) {
                total_ops += (long long)(k + 1) * count;
            }

            if (next_power_of_4 == -1 || next_power_of_4 > n) {
                break;
            }
            
            power_of_4 = next_power_of_4;
            k++;
        }
        
        return total_ops;
    }
    
    long long minOperations(vector<vector<int>>& queries) {
        long long total_result = 0;
        for (const auto& q : queries) {
            long long l = q[0];
            long long r = q[1];
            
            long long total_single_ops_in_range = calculateTotalSingleOps(r) - calculateTotalSingleOps(l - 1);
            
            long long min_ops_for_query = (total_single_ops_in_range + 1) / 2;
            
            total_result += min_ops_for_query;
        }
        return total_result;
    }
};