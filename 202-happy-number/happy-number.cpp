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

        //use slow fast pointer 
        int slow = n;
        int fast = n;

        while(fast != 1){
            slow = sum(slow);//this is just trying to calculate the next version of n , it move for 1 step
            fast = sum(fast);//and this works for two times 
            fast = sum(fast);

            if(slow == fast &&  slow != 1){
                //the cycle is being formed
                return false;
                
            }
        }
        return true;

        
    }
};