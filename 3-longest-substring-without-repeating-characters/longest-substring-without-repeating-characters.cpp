class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        vector<int> freq(256,0);
        int n   = s.size();
        int left = 0;
        

        for(int right = 0; right < n; right++){

            unsigned char rc = s[right];
            ++ freq[rc];

            while(freq[rc] > 1){
                unsigned char lc = s[left++];

                --freq[lc];
            }

            maxLength = max(maxLength,right - left + 1);
        }

        return maxLength;
        
    }
};