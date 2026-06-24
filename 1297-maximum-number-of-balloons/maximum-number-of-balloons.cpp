class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balloon";
        unordered_map<char,int> tFreq;
        unordered_map<char,int> sFreq;

        for(char ch : s){
            sFreq[ch]++;
        }

        for(char ch : text){
            tFreq[ch]++;
        }

        int ans = INT_MAX;
        for(auto &it : sFreq){
            ans = min(ans,tFreq[it.first] / it.second);
        }
        return ans;
    }
};