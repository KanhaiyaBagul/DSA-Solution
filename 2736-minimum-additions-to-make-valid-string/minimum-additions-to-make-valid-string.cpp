class Solution {
public:
    int addMinimum(string word) {
        
        int result = 0;
        int i = 0;
        while(i < word.size()){
            if(word.substr(i,3) == "abc"){
                result += 0;
                i += 3;
            }else if(word.substr(i,2) == "ab" || word.substr(i,2) == "bc" || word.substr(i,2) == "ac"){
                result  += 1; 
                i+=2;

            }else{
                result += 2;
                i++;
            }
        }
        return result;

        
    }
};