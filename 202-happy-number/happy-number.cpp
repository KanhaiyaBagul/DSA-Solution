class Solution {
public:

    int sum(int n){
        int numSum = 0;

        while(n > 0){
            int d = n % 10;
            numSum = numSum + d * d;
            n = n / 10;
        }

        return numSum;
    }
    bool isHappy(int n) {

        int slow = n;
        int fast = n;

        while(fast != 1){
            slow = sum(slow);
            fast = sum(fast);
            fast = sum(fast);

            if(slow == fast &&  slow != 1){
                //the cycle is being formed
                return false;
                
            }
        }
        return true;

        
    }
};