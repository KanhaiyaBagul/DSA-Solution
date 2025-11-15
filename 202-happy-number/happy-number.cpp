class Solution {
public:
    int sum(int n){
        int result = 0;
        while(n > 0){
            int d = n % 10;
            result = result + (d*d);
            n = n / 10;
        }

        return result;
    }
    bool isHappy(int n) {
        int slow = n; 
        int fast = n;

        while(fast != 1){
            slow = sum(slow);
            fast = sum(fast);
            fast = sum(fast);

            if(slow == fast && slow != 1){
                return false;
            }
        }
        return true;
        
    }
};