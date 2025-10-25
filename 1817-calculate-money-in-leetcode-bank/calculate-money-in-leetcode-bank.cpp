class Solution {
public:
    int totalMoney(int n) {
        int start = 1;
        int recursion = 1;
        int finalAns = 0;
        
        for(int i = 1; i <= n; i++){
            finalAns += start;
            start++;

            if(i%7 == 0){
                recursion++;
                start = recursion;
            }
        }
        return finalAns;
        
    }
};