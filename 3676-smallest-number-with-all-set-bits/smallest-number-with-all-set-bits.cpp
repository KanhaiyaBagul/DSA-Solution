class Solution {
public:
    int smallestNumber(int n) {

        int ans = 0;

        for(int i = 0; i < 32; i++){
            ans = (2 << i) - 1;
            if(ans >= n){
                return ans;
            }
        }
        return -1;
        
    }
};