class Solution {
public:
    string longestPalindrome(string s) {

        if(s.length() <= 1){
            return s;
        }
        string ans = "";
        
        for(int i = 1; i < s.length(); i++){

            int low = i;
            int high = i;
            //calculate for odd
            while((low >= 0 && high < s.length()) && s[low] == s[high]  ){
                low --;
                high++;
            }
            string palindrome = s.substr(low + 1, high - low - 1);
            if(ans.length() < palindrome.length()){
                ans = palindrome;
            }


            //calculate for even
            low = i - 1;
            high = i;

            while((low >= 0 && high < s.length()) && s[low] == s[high]){
                low --;
                high++;
            }
             palindrome = s.substr(low + 1, high - low - 1);
            if(ans.length() < palindrome.length()){
                ans = palindrome;
            }
        }
        return ans;
        
    }
};