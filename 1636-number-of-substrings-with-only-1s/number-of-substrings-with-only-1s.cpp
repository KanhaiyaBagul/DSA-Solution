class Solution {
public:
    int numSub(string s) {
        
        const long long mod =  1000000007;
        int len = 0;
        int result = 0;
        for(char ch : s){
            int nums = 0;
            if(ch == '1'){
                len++; 
                result = (result + len) % mod;       
            }else{
                
                len = 0;
            }

        }
        
        return result;
        
    }
};