class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        long long prev = n - 1;
        return (n & prev) == 0 ? true : false; 
        
    }
};