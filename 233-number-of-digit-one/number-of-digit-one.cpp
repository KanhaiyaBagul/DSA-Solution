class Solution {
public:
    int dp[12][2][12]; //index, tight , count
    
    int solve(string& s, int idx,int tight, int cnt){
        if(idx == s.size()){
            return cnt;
        }

        if(dp[idx][tight][cnt] != -1) return dp[idx][tight][cnt]; //memoization

        int limit = (tight == 1 ? s[idx] - '0' : 9);//this is for the restriction
        int ans = 0;

        for(int i = 0; i <= limit; i++){
            int updatedCnt = cnt + (i == 1 ? 1 : 0);//calculate the updated count
            ans += solve(s,idx + 1, (tight && (i == s[idx] - '0')),updatedCnt);
        }
        return dp[idx][tight][cnt] = ans;

    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));//intilize the array
        return solve(s,0,1,0);
        
    }
};