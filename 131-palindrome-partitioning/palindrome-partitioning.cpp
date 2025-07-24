class Solution {
public:
    //Helper function to find if the string is palindrome or not
    bool isPalindrome(string current){
        int i = 0;
        int j = current.size() - 1;

        while(i <= j ){
            if(current[i] != current[j]){
                return false;
            }
            i++;
            j--;
            
        }

        return true;
    }
    
    //Here is the main recursive function 
    void part(int index , string s, vector<string>& current, vector<vector<string>>& result){
        if(index == s.size()){//This is the base conditioon
            result.push_back(current);
            return;
        }
        string temp ="";//it store the temporary string to check if it is palindrome or not
        for(int i = index; i < s.size(); i++){
            temp += s[i];
            if(isPalindrome(temp)){
                current.push_back(temp);
                part(i + 1,s,current,result);//This function check if the other string are palindrome or not , It check forward
                current.pop_back();//This is the main logic of back tracking if any condition fails it remove the failcondion element and use for the previous one

            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> current;
        vector<vector<string>> result;

        part(0,s, current, result);
        return result;
        
    }
};