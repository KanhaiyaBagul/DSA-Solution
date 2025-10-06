class Solution {
public:
    int reverse(int x) {
        long long n = 0;
        bool isNegative = x < 0 ? true: false;

        x = abs((long long)x);
    

        while(x > 0){
            n = n * 10 + x % 10;
            x = x / 10;
        }

        if(n > INT_MAX || n < INT_MIN){
            return 0;
        }

        return isNegative? -n : n;
        
    }
};