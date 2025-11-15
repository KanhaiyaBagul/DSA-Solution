class Solution {
public:
    bool isPerfectSquare(int num) {
        long long n = 1;
        while(n*n <= num){
            int result = n * n;
            if(result == num){
                return true;
            }
            n++;
        }
        return false;
    }
};