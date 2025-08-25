class Solution {
public:
    int balancedStringSplit(string s) {
        int maxString = 0;

        int R = 0;
        int L = 0;

        for(char ch : s){
            if(ch == 'R') R++;
            else L++;

            if(R == L){
                R=0;
                L=0;
                maxString++;
            }
        }

        return maxString;

        
    }
};