class Solution {
public:
    bool isPowerOfFour(int n) {
        
        
        for(int i = 0; i < 32; i+=2){
            int num = 1;
            int bit;
            bit = num << i;
            if(bit == n){
                return true;
                
            }
        }
        return false;
    }
};