class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            vector<int> freq(26, 0);//store the Freq
            int maxFreq = 0;//max freq
            int dist = 0;//store dist numbers

            for (int j = i; j < s.size(); j++) {

                int idx = s[j] - 'a';
                //count dist char
                if (freq[idx] == 0) {
                    dist++;
                }

                freq[idx]++;//add the freq

                maxFreq = max(maxFreq, freq[idx]);//calc the maxFreq

                int len = j - i + 1;//len of our substring
                //if the freq of each element is equal then store the max len of it
                //if dist char * max freq , means all have same freq then they have the same freq m
                if (dist * maxFreq == len) {
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};