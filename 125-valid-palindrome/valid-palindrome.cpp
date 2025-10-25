class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";

        for(char ch : s){
            if(isalnum(ch)){
                newStr+=tolower(ch);
            }
        }

        int i = 0;
        int j = newStr.size()-1;

        while(i<=j){
            if(newStr[i] != newStr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

        
    }
};