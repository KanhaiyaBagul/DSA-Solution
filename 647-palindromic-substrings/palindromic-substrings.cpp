class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        int count = 0;
        if(s.size() <= 1 ){
            
            return n;
        }
        
        for(int i = 0; i < n; i++){
            int low = i;
            int high = i;
            
            //for odd
            while(low >=0 && high < n && s[low] == s[high]){
                low--;
                high++;
                count++;
                
            }
             
             
             low = i;
             high = i + 1;
            while(low >=0 && high < n && s[low] == s[high]){
                low--;
                high++;
                count++;
                
            }
            
            
        }
        return count;
        
        
    }
        
    
};