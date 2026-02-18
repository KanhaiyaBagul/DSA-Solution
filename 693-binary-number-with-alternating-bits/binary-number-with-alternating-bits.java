class Solution {
    public boolean hasAlternatingBits(int n) {
        int prev = -1;

        while(n > 0){
            int bitMask = n & 1;
            n = n >> 1;
            

            if(prev == bitMask){
                return false;
            }


            prev = bitMask;

        }
        return true;
        
    }
}