class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ss , tt;

        for(char ch : s){
            ss[ch]++;
        }

        for(char ch : t){
            tt[ch]++;
        }
        return ss == tt;
    }
};