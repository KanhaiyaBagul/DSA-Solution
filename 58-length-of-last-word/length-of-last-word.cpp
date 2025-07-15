class Solution {
public:
    int lengthOfLastWord(string s) {
        

        int last  = s.size() - 1;
        int count = 0;
        while((int) s[last] == 32){
            last--;
        }
        while(  last >=0 && (int)s[last] != 32){

            count++;
            last--;
        }
        return count;
        
    }
};