class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> freq;
        int n = s.size();

        int count = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            char ch = s[right];
            freq[ch]++;

            while(freq.size() == 3){
                count += n - right;

                freq[s[left]]--;
                if(freq[s[left]] == 0){
                    freq.erase(s[left]);
                }
                left++;
            }

        }
        return count;
        
    }
};