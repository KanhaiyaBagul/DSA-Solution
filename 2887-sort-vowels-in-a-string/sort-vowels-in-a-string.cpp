class Solution {
public:
    string sortVowels(string s) {
        //fint the vowels string
        string str = "";

        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E'  || ch == 'I' || ch == 'O'|| ch == 'U'){
                str += string(1,ch);
            }
        }

        sort(str.begin(), str.end());
        int j = 0;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E'  || ch == 'I' || ch == 'O'|| ch == 'U'){
                s[i] = str[j++];
            }
        }
        return s;
        
    }
};