class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int aCount = 0;
        int bCount = 0;

        for(char ch : s){
            if(ch == 'a'){
                aCount++;
            }else{
                bCount++;
            }
        }
        return abs(aCount - bCount);
        
    }
};