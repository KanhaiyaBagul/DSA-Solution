class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char , int> freq;
        //count the frequency
        for(char ch : s){
            freq[ch]++;
        }

        int result = 0;
        bool isOddcount = false;

        for(auto& pair : freq){
            if(pair.second % 2 == 0){//count the even count
                result += pair.second;

            }else{
                result += pair.second - 1;// also get the even count from odd
                isOddcount = true;
            }
        }

        if(isOddcount) result = result + 1;

        return result;



        
    }
};