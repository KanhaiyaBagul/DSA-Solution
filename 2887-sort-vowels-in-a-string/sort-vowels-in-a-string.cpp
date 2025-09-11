class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string sortVowels(string s) {
        string vowel = "";
        //find the vowel string
        for (char ch : s) {
            if (isVowel(ch)) {
                vowel += ch;
            }
        }

        //sort the vowel string
        sort(vowel.begin(), vowel.end());

        int j = 0;
        //if we find the vowel in the s then replaced with the sorted
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isVowel(ch)) {
                s[i] = vowel[j++];
            }
        }
        return s;
    }
};