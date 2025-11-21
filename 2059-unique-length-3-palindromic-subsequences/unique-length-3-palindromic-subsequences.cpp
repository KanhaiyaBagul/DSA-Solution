class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> right(26,-1);
        vector<int> left(26,-1);


        for(int i = 0; i < s.size();i++){
            int c = s[i] - 'a';

            if(left[c] == -1) left[c] = i;

            right[c] = i;
        }


        int ans = 0;
        for(int i = 0; i < 26; i ++){
            if(left[i] == -1 || left[i] == right[i]) continue;

            unordered_set<char> mid;

            for(int k = left[i] + 1; k < right[i]; k++){
                mid.insert(s[k]);
            }
            ans += mid.size();

        }
        return ans;

    }
};